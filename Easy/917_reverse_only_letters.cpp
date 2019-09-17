/**
 *
 * Time Complexity: O(N) where N is number of chars in string S
 *
 * Runtime: 12 ms, Faster than 66.25%
 * Memory: 10.8 MB, Less than 60.00%
 */
class Solution {
public:

    string reverseOnlyLetters(string S) {
        int ind1 {0};
        int ind2 {S.size()-1};
        while (true) {
            while (!isalpha(S[ind1]) && ind1 < ind2) ind1++;
            while (!isalpha(S[ind2]) && ind1 < ind2) ind2--;
            if (ind1 >= ind2) break;
            swap(S[ind1], S[ind2]);
            ind1++; ind2--;
            }
        return S;
        }
};