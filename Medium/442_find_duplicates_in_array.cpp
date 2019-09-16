/**
 * Challenge pertains to having a O(N) runtime
 * as well as not using any extra space.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * Runtime: 112 ms, Faster than 87.68%
 * Memory: 14.8 MB, Less than 100.00%
 */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        int n = nums.size();
        vector<int> duplicates;

        /*
         * Swap array elements with their
         * array position by value.
         *
         * Case 1:
         * If one entry is detected, the value at the
         * corresponding array position will be 0.
         * If detected twice, the value at the array
         * position will be negative.
         *
         * Case 2:
         * If a value is being swapped with
         * a value that is already a 0 (detected once),
         * then sub with value n+1, and subtract as normal.
         */
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (num > 0 && num != n+1) {
                // Case 1
                if (nums[num-1] != 0) {
                    swap(nums[i], nums[num-1]);
                    nums[num-1] -= num;
                    i--;
                // Case 2
                } else {
                    nums[i] == n+1;
                    nums[num-1] -= num;
                }
            }
        }

        /*
         * Iterate over nums array and for every
         * position with a negative value, append it
         * to the duplicates vector array as a pos value.
         */
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                duplicates.push_back(-nums[i]);
            }
        }
        return duplicates;
    }
};