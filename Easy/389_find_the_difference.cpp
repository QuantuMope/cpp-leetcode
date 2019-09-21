/**
 * Use an unordered map to store counts of
 * chars in string s. Then decrement while
 * running through chars in string t.
 * First negative count is output.
 *
 * Time Complexity: O(S) where S is size of strings
 *
 * Runtime: 4 ms, Faster than 84.80%
 * Memory: 9 MB, Less than 88.89%
 */
class Solution {
public:
    char findTheDifference(string s, string t) {
        if (s.size() == 0) return t[0];
        unordered_map<char, int> count;
        for (auto &c : s) count[c] += 1;
        for (auto &c : t) {
            count[c] -= 1;
            if (count[c] < 0) return c;
        }
        return '0'; // for compile
    }
};