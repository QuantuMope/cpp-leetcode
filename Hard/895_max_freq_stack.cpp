#include <stack>
#include <iostream>
#include <unordered_map>
using namespace std;
/**
 * Had to look up a hint as to proper map
 * mappings in order to meet time constraints.
 * In my own implementation I used three maps:
 * 1. freq ----> number  <int, unordered_set>
 * 2. number ----> pos   <int, stack>
 * 3. number ----> freq  <int, int>
 * Below is my implementation after the hint.
 *
 * Deleting unused map entries actually significantly
 * increases memory usage.
 * Probably due to inefficient creation of map entries
 * after unnecessary deletion.
 *
 * Since using unordered_maps,
 * Time Complexity: O(1) on average
 *
 * Space Complexity: O(P) where P is push entries
 *
 * Runtime: 232 ms, Faster than 84.55%
 * Memory: 74.7 MB, Less than 91.67%
 */

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
class FreqStack {
public:
    unordered_map<int, stack<int>> order;   // freq ----> pos
    unordered_map<int, int> freq;         // number ----> freq
    int max_freq {0};
    FreqStack() {
    }

    void push(int x) {
        freq[x] += 1;
        int curr_freq = freq[x];
        order[curr_freq].push(x);
        if (curr_freq > max_freq) max_freq = curr_freq;
    }

    int pop() {
        int output = order[max_freq].top(); order[max_freq].pop();
        if (order[max_freq].empty()) max_freq--;
        freq[output] -= 1;
        return output;
    }
};

int main() {
    // Output should be 4, 6, 1, 1, 4, 2, 3, 9, 0, 4
    FreqStack test;
    test.push(4);
    test.push(0);
    test.push(9);
    test.push(3);
    test.push(4);
    test.push(2);
    cout << test.pop() << endl;
    test.push(6);
    cout << test.pop() << endl;
    test.push(1);
    cout << test.pop() << endl;
    test.push(1);
    cout << test.pop() << endl;
    test.push(4);
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    cout << test.pop() << endl;
    return 0;
}