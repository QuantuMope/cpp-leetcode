/**
 *
 * Time Complexity: O(W*L) where W is the number of words
 *                           and L is the number of letters per word
 *
 * Runtime: 4 ms, Faster than 85.79%
 * Memory: 9.4 MB, Less than 81.82%
 */
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        /*
         * Use a map to store pattern -> word mappings
         * Use a set to store which words have already been mapped
         */
        map<char, char> dict;
        set<char> assigned;
        vector<string> matches;

        for (auto word : words) {
            for (int i = 0; i < word.size(); i++) {
                // Assign unassigned patterns to unassigned words
                if (!dict.count(pattern[i]) && !assigned.count(word[i])) {
                    dict.insert(pair<char, char>(pattern[i], word[i]));
                    assigned.insert(word[i]);
                // Detect inconsistent mappings
                } else if (word[i] != dict[pattern[i]]) { break; }

                if (i == word.size()-1) matches.push_back(word);
            }
            dict.clear(); assigned.clear();
        }
        return matches;
    }
};