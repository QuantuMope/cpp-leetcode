#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts(nums.size(), 0);
        map<int, int> occurrences;
        int lowest {0};
        for (int i = nums.size()-1; i > -1; i--) {
            if (nums[i] < lowest) lowest = nums[i];
            if (occurrences.count(nums[i])) occurrences[nums[i]] += 1;
            else  occurrences.insert(pair<int, int>(nums[i], 1));

            for (int e = lowest; e < nums[i]; e++) {
                if (occurrences.count(e)) counts[i] += occurrences[e];
            }
        }
        return counts;
    }
};

int main() {
    // Should be [1, 0]
    Solution test;
    vector<int> input {-1, -2};
    vector<int> output = test.countSmaller(input);
    for (auto &ele : output) {
        cout << ele << endl;
    }
    return 0;
}