#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <time.h>
#include "randomizer_meta.hpp"

namespace fs = std::filesystem;
using namespace std;

/*
 * Randomize a single file in archive to do
 * Will use spaced repetition to suggest next thing to do
 */

const int DELAY = 1; //day
const int UNSURE = 3; //days
const int DECENT = 7; //days
const int GOOD = 15; //days
const int EZ = 30; //days
const int MAX_LIMIT = 10; //10 exercise to consider

typedef chrono::duration<int, std::ratio<60 * 60 * 24>> days_type;

auto read_file(std::string_view path) -> std::string {
  constexpr auto read_size = std::size_t(4096);
  auto stream = std::ifstream(path.data());
  stream.exceptions(std::ios_base::badbit);

  auto out = std::string();
  auto buf = std::string(read_size, '\0');
  while (stream.read(&buf[0], read_size)) {
    out.append(buf, 0, stream.gcount());
  }
  out.append(buf, 0, stream.gcount());
  return out;
}

auto parse(string &file_contents) -> unordered_map<string, vector<chrono::time_point<chrono::system_clock>>> {
  vector<vector<string>> temp;
  vector<string> kek;
  string word = "";
  for (char file_content: file_contents) {
    if (file_content != ',') {
      word += file_content;
    } else if (file_content == '\n') {
      temp.push_back(kek);
      kek.clear();
    } else {
      kek.push_back(word);
      word = "";
    }

  }

  unordered_map<string, vector<chrono::time_point<chrono::system_clock>>> d;
  for (int i = 0; i < temp.size(); ++i) {
    d[temp[i][0]] = vector<chrono::time_point<chrono::system_clock>>();
    for (int j = 1; j < temp[i].size(); ++j) {
      std::tm tm = {};
      std::stringstream ss(temp[i][j]);
      ss >> std::get_time(&tm, "%b %d %Y %H:%M:%S");
      auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
      d[temp[i][0]].push_back(tp);
    }
  }

  return d;
}

auto write(unordered_map<string, vector<chrono::time_point<chrono::system_clock>>> &contents,
           const string &archive_meta_path) {
  std::ofstream ofs(archive_meta_path);
  for (auto &[k, times]: contents) {
    ofs << k << ",";
    auto last_time = times.end();
    for (int i = 0; i < times.size(); ++i) {
      auto time = times[i];
      auto ktime = std::chrono::system_clock::to_time_t(time);
      ofs << std::put_time(std::localtime(&ktime), "%b %d %Y %H:%M:%S");
      if (i != times.size() - 1) {
        ofs << ",";
      }
    }
    ofs << "\n";
  }
  ofs.close();
}

auto select_next(unordered_map<string, vector<chrono::time_point<chrono::system_clock>>> &contents) -> string {
  if (contents.empty()) {
    return "";
  }

  srand(time(NULL));

  // NOTE: middle int is random number to force uniform distribution given same days delta on first int
  vector<pair<int, pair<int, string>>> sorter;
  int max_diff = 0;
  for (auto &[s, times]: contents) {
    if (times.size() < 2) {
      sorter.push_back({INT_MAX, {rand(), s}});
    } else {
      int delta = chrono::duration_cast<days_type>(times[times.size() - 1] - times[times.size() - 2]).count();
      max_diff = max(max_diff, delta);
      sorter.push_back({delta, {rand(), s}});
    }
  }

  for (auto &[days, name]: sorter) {
    if (days == INT_MAX) {
      days = max_diff;
    }
  }

  sort(sorter.begin(), sorter.end());
  int ind = rand() % MAX_LIMIT;
  if (ind > sorter.size()) ind = sorter.size() - 1;
  return sorter[ind].second.second;
}

int main() {

  string archive_meta_filename = "_archive_meta.txt";
  string path = ARCHIVE_PATH;
  string archive_meta = string(ARCHIVE_PATH) + "/" + archive_meta_filename;

  if (!fs::exists(archive_meta)) {
    std::ofstream ofs(archive_meta);
    ofs.close();
  }

  //read file
  auto file_contents = read_file(archive_meta);
  auto contents = parse(file_contents);

  vector<string> keys;
  for (const auto &entry: fs::directory_iterator(path)) {
    string filename = entry.path().filename().string();
    keys.push_back(filename);

    if (contents.find(filename) == contents.end()) {
      contents[filename].push_back(std::chrono::system_clock::now());
    }
  }
  contents.erase(archive_meta_filename);

  cout << "Randomizer running...\n";

  string selected_file = select_next(contents);
  if (selected_file.empty()) {
    cout << "No exercise found, archive folder is empty\n";
    return 0;
  }
  if (contents.find(selected_file) == contents.end()) {
    cout << selected_file << " not found in archive folder\n";
    return 0;
  }
  cout << "Solve this file: " << selected_file << "\n";

  cout << "Difficulty\n" <<
       " (1). Delayed\n" <<
       " (2). Unsure\n" <<
       " (3). Decent\n" <<
       " (4). Good\n" <<
       " (5). Ez\n" <<
       " (6). Give up\n" <<
       "Enter difficulty: ";

  int days = 0;
  bool shouldRun = true;
  int input2;
  cin >> input2;
  do {
    shouldRun = false;
    switch (input2) {
      case 1:
        days = DELAY;
        break;
      case 2:
        days = UNSURE;
        break;
      case 3:
        days = DECENT;
        break;
      case 4:
        days = GOOD;
        break;
      case 5:
        days = EZ;
        break;
      default:
        shouldRun = false;
    }
  } while (shouldRun);

  auto new_solved = std::chrono::system_clock::now() + std::chrono::hours(days * 24);
  contents[selected_file].push_back(new_solved);

  write(contents, archive_meta);

  return 0;
}