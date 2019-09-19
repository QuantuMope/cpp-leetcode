/**
 * This is a very trivial challenge.
 *
 * Time Complexity: O(N) where N is size of string
 *
 * Runtime: 16 ms, Faster than 84.89%
 * Memory: 10.2 MB, Less than 82.93%
 */
class Solution {
public:
    bool judgeCircle(string moves) {
        int x {0}, y {0};
        for (auto &c : moves) {
            if (c == 'U') y++;
            else if (c == 'D') y--;
            else if (c == 'L') x--;
            else               x++;
        }
        return x == 0 && y == 0;
    }
};