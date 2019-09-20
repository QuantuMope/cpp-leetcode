/**
 * This challenge requires a O(NlogN) time complexity
 * where N is size of nums array
 *
 * Insert operations unordered_map are O(1) on avg
 * Push and pop operations on priority queue are O(logN)
 * Push and pop operations on stacks are O(1)
 * Therefore:
 *
 * Time Complexity: O(NlogN) where N is size of nums
 *
 * Runtime: 20 ms, Faster than 79.58%
 * Memory: 11.9 MB, Less than 22.58%
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == 0) return vector<int>();

        unordered_map<int, int> freq; // number --> freq
        unordered_map<int, stack<int>> number;  // freq --> number
        priority_queue<int> high_freqs;
        vector<int> output(k, 0);

        // First Pass: map numbers to their freq
        for (auto &num : nums) {
            if (freq.count(num)) freq[num] += 1;
            else freq.emplace(make_pair(num, 1));
        }

        // Second Pass: map freq to numbers using a stack
        // Create priority queue of freqs
        for (auto &ele : freq) {
            high_freqs.push(ele.second);
            if (!number.count(ele.second))
                number.emplace(make_pair(ele.second, stack<int>()));
            number[ele.second].push(ele.first);
        }

        // Pop k freqs off priority queue and
        // add corresponding numbers to output vec
        for (int i = 0; i < k;) {
            int max_freq = high_freqs.top();
            while (!number[max_freq].empty()) {
                output[i] = number[max_freq].top();
                number[max_freq].pop();
                high_freqs.pop();
                i++; if (i == k) break;
            }
        }
        return output;
    }
};
