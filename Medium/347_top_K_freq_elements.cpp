/**
 * This challenge requires a O(NlogN) time complexity
 * where N is size of nums array
 *
 * Insert operations unordered_map are O(1) on avg
 * Push and pop operations on priority queue are O(logN)
 * Therefore:
 *
 * Time Complexity: O(NlogN) where N is size of nums
 *
 * Runtime: 16 ms, Faster than 95.53%
 * Memory: 11.4 MB, Less than 96.77%
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == 0) return vector<int>();

        unordered_map<int, int> freq; // number --> freq
        priority_queue<pair<int, int>> high_freqs;
        vector<int> output(k, 0);

        for (auto &num : nums) freq[num] += 1;

        for (auto &ele : freq) {
            high_freqs.push(make_pair(ele.second, ele.first));
        }

        for (int i = 0; i < k; i++) {
            output[i] = high_freqs.top().second;
            high_freqs.pop();
        }
        return output;
    }
};
