/**
 * This is a very trivial challenge.
 *
 * Time Complexity: O(N) where N is size of string
 *
 * Runtime: 0 ms, Faster than 100.00%
 * Memory: 8.2 MB, Less than 100.00%
 */
class Solution {
public:
    string defangIPaddr(string address) {
        string output;
        for (auto c : address) {
            if (c == '.') output += "[.]";
            else          output += c;
        }
        return output;
    }
};