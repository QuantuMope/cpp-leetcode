/**
 * This challenge requires that the array be altered
 * in-place and that number of operations are minimized.
 *
 * Use a queue to store locations of non-zero entries.
 * Then pass through the array once more and swap out
 * non-zeros with the zero closest to the left side so
 * long as the zero is before the queue's output.
 *
 * Time Complexity: O(N) where N is size of nums array
 *
 * Runtime: 12 ms, Faster than 96.91%
 * Memory: 9.6 MB, Less than 62.50%
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 1) return;
        int zeros {0};
        queue<int> nonzeros;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) nonzeros.push(i);
            else zeros += 1;
        }
        if (zeros == 0) return; // end if no zeros
        int curr_zero {0};
        while (!nonzeros.empty()) {
            while (nums[curr_zero] != 0) curr_zero++;
            if (curr_zero < nonzeros.front())
                swap(nums[curr_zero], nums[nonzeros.front()]);
            nonzeros.pop();
        }
    }
};