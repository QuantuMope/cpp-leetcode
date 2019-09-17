/**
 * Challenge pertains to having a O(N) runtime
 * as well as not using any extra space.
 *
 * Time Complexity: O(N) where N is number of chars in string S
 * Space Complexity: O(1)
 *
 * Runtime: 52 ms, Faster than 91.87%
 * Memory: 11.5 MB, Less than 100.00%
 */
class Solution {
public:

    void add_wrap_around(char &input, int shift) {
        /*
         * Wrap around equation:
         * a -> 97 , z -> 122
         * so input = 96 + (input + shift - 122)
         * =  input = input + shift - 26
         */
        if (input + shift <= 122)  input += shift;
        else                       input += shift - 26;
    }

    string shiftingLetters(string S, vector<int>& shifts) {
        int shift {0};
        // Traverse shifts vector in reverse order
        for (int i = shifts.size()-1; i > -1; i--){
            shift = (shift + shifts[i] % 26) % 26;
            add_wrap_around(S[i], shift);
        }
        return S;
    }
};