/**
 * Originally used hash table but realized
 * that an array could be used in its place since
 * people are labelled from 1 to N. Very fast
 * as we can initialize array to appropriate size
 * and array indexing is more efficient than hash
 * tables.
 *
 * Time Complexity: O(N) where N is the number of people
 * Space Complexity: O(N)
 *
 * Runtime: 148 ms, Faster than 92.55%
 * Memory: 42.3 MB, Less than 100.00%
 */
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if (trust.size() == 0) return N;
        vector<int> count(N+1, 0);
        int store {-1};
        for (auto &pair : trust) {
            count[pair[0]] += N; // disqualifies candidate
            count[pair[1]] += 1;
            if (count[pair[1]] == N-1) store = pair[1];
            else if (pair[1] == store || pair[0] == store) store = -1;
        }
        return store;
    }
};