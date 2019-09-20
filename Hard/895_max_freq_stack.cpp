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
 * Time Complexity: O(1) on average
 *                  can be O(N) worse case due to
 *                  map count() calls
 * Space Complexity: O(P) where P is push entries
 *
 * Poor Memory Usage as shown.
 * The commented out statements actually
 * increase usage. Probably due to in efficient
 * creation of new map entries after deletion.
 *
 * Runtime: 232 ms, Faster than 84.55%
 * Memory: 82.3 MB, Less than 8.33%
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
        if (freq.count(x)) freq[x] += 1;
        else freq.emplace(x, 1);
        int curr_freq = freq[x];
        if (order.count(curr_freq)) order[curr_freq].emplace(x);
        else {
            order.emplace(curr_freq, stack<int>());
            order[curr_freq].emplace(x);
        }

        if (curr_freq > max_freq) max_freq = curr_freq;
    }

    int pop() {
        int output = order[max_freq].top();
        order[max_freq].pop();
        if (order[max_freq].empty()) {
//            order.erase(max_freq);
            max_freq--;
        }
        freq[output] -= 1;
//        if (freq[output] == 0) freq.erase(output);
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