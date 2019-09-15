/**
 *  Complexity: O(N) where N is chars in string S
 *
 *  Runtime: 0 ms,  Faster than 100.0%
 *  Memory : 8.4 MB, Less than 84.62%
 */
class Solution {
public:
    int minAddToMakeValid(string S) {

        int min_add = 0;
        int front_paran = 0;
        int back_paran = 0;

        for (char paran : S) {

            if (paran == '(') {
                front_paran++;
            } else {
                back_paran++;
            }

            // Takes care of cases where ')' is found
            // without a '(' in front of it
            if (paran == ')' && front_paran < back_paran) {
                back_paran--;
                min_add++;
            }
        }
        // Second term takes care of all remaining '('s
        return min_add + (front_paran - back_paran);
    }
};