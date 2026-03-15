// Doing naive generation will result in TLE when prime and n is big.
// Instead of trying each number whether its divisible
// Just generate it from the number we already have.
class Solution {
public:
    typedef unsigned long long ull;
    priority_queue<ull, vector<ull>, greater<ull>> pq;
    vector<ull> seq;
    unordered_set<int> dedup;

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        pq.push(1);
        while (seq.size() < n) {
            auto curr = pq.top();
            pq.pop();

            if (dedup.find(curr) != dedup.end()) {
                continue;
            }

            seq.push_back(curr);
            dedup.insert(curr);

            for (auto& p : primes) {
                ull k = p * curr;
                pq.push(k);
            }
        }

        return seq.back();
    }
};
