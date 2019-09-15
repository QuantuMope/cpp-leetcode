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
