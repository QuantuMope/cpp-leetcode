/**
 * Use a map data structure to keep track of possible
 * complements that were previously seen.
 *
 * Time Complexity: O(N) where N is ints in vector
 * Space Complexity: O(N) ""
 *                   brute force method would be
 *                   O(N**2) and O(1), respectively
 *
 * Runtime: 8 ms, Faster than 92.50%
 * Memory: 10.1 MB, Less than 50.95%
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> seen;
        int i {0};
        for (; i < nums.size(); i++) {
            int diff {target - nums[i]};
            if (seen.count(diff) && seen[diff] != i) break;
            seen.emplace(nums[i], i);
        }
        return vector<int> {seen[target-nums[i]], i};
    }
};