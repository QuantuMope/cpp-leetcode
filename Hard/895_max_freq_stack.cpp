/**
 * Not completed
 */
#include <set>
#include <stack>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
class FreqStack {
public:

    unordered_map<int, unordered_set<int>> freq;      // freq ----> number
    unordered_map<int, stack<int>> order;   // number ----> pos
    unordered_map<int, int> number;         // number ----> freq
    int pos {0};
    int max_freq {1};
    FreqStack() {

    }

    void push(int x) {
        if (order.count(x)) {
            order[x].push(pos);
            freq[number[x]].erase(x);
            number[x] += 1;
            if (freq.count(number[x])) freq[number[x]].insert(x);
            else {
                unordered_set<int> set_input;
                set_input.insert(x);
                freq.insert(pair<int, unordered_set<int>>(number[x], set_input));
                if (number[x] > max_freq) max_freq = number[x];
            }
        }
        else {
            stack<int> stack_input;
            stack_input.push(pos);
            order.insert(pair<int, stack<int>>(x, stack_input));
            number.insert(pair<int, int>(x, 1));
            if (freq.count(1)) freq[1].insert(x);
            else {
                unordered_set<int> set_input;
                set_input.insert(x);
                freq.insert(pair<int, unordered_set<int>>(1, set_input));
            }
        }
        pos++;
    }

    int pop() {
        int later_num {0};
        int later_pos {-1};
        for (auto &c : freq[max_freq]) {
            if (order[c].top() > later_pos) {
                later_pos = order[c].top();
                later_num = c;
            }
        }
        order[later_num].pop();
        if (order[later_num].empty()) order.erase(later_num);
        freq[number[later_num]].erase(later_num);
        if (freq[number[later_num]].empty()) {
            freq.erase(number[later_num]);
            max_freq--;
        }
        number[later_num] -= 1;
        if (number[later_num] != 0) freq[number[later_num]].insert(later_num);
        else number.erase(later_num);
        return later_num;
    }
};

int main() {

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