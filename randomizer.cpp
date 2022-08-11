#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>
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

auto parse(string &file_contents) -> unordered_map<string, vector<tpp> {
  vector<vector<string>> temp;
  vector<string> kek;
  string tok = "";
  for (char file_content: file_contents) {
    if (file_content != ',') {
      tok += file_content;
    } else {
      kek.push_back(tok);
      tok = "";
    }

    if (file_content == '\n') {
      temp.push_back(kek);
      kek.clear();
    }
  }

  unordered_map<string, vector<time_t>> d;
  for(int i = 0; i < temp.size(); ++i){
    d[temp[i][0]] = vector<time_t>();
    for(int j = 1; j < temp[i].size(); ++j){
      std::tm tm = {};
      std::stringstream ss(temp[i][j]);
      ss >> std::get_time(&tm, "%b %d %Y %H:%M:%S");
      auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
      d[temp[i][0]].push_back(j);
    }
  }

  return d;
}

int main() {

  string path = ARCHIVE_PATH;
  string archive_meta = string(ARCHIVE_PATH) + "/" + "archive_meta.txt";

  if (!fs::exists(archive_meta)) {
    std::ofstream ofs(archive_meta);
    ofs.close();
  }

  //read file
  auto file_contents = read_file(archive_meta);
  auto content = parse(file_contents);

  for (const auto &entry: fs::directory_iterator(path)) {
    string filename = entry.path().filename().string();
  }


}