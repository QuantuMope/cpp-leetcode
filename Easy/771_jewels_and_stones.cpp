/**
    Give up memory efficiency for speed
    by using a set data structure.

    Time Complexity: O(J+S) where J is jewels
                            and S is stones

    Runtime: 0 ms,   Faster than 100.00%
    Memory : 8.6 MB, Less than 32.50%
*/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set <char> jewels (J.begin(), J.end());
        int num_jewels = 0;
        for (char stone : S) {
            if (jewels.count(stone)) num_jewels++;
        }
        return num_jewels;
    }
};
