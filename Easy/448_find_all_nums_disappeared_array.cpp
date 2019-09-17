/**
 * Similar to challenge 442.
 *
 * Challenge pertains to having a O(N) runtime
 * as well as not using any extra space.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * Runtime: 112 ms, Faster than 87.20%
 * Memory: 14.7 MB, Less than 100.00%
 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;

        // Swap in-place. Duplicates are changed to -1.
        // Note: 1 <= arr <= n. Thus, offsets of +1, -1
        // used where appropriate.
        for (int i = 0; i < n; i++) {
            int num = nums[i];

            if (num == -1 || num == i+1) continue;

            if (num != i+1 && num == nums[num-1]) {
                nums[i] = -1;
                continue;
            }
            if (num != i+1) {
                swap(nums[i], nums[num-1]);
                i--;
            }

        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != -1) continue;
            output.push_back(i+1);
        }
        return output;
    }
};