/**
 * Not completed
 */
#include <vector>
#include <map>
#include <utility>

using namespace std;
class FreqStack {
public:
    typedef pair<int, vector<int>> num_pos;
    multimap<int, num_pos> map;
    int max_freq;
    int stack_size;
    vector<int> max_vals;

    FreqStack() {
        max_freq = 0;
        stack_size = 0;
    }

    void push(int x) {
        if (!map.count(x)) {
            vector<int> pos {stack_size++};
            num_pos num_and_pos = make_pair(x, pos);
            map.insert(pair<int, num_pos>(1, num_and_pos));
        } else {
            map.find(x)->second.second.push_back(stack_size++);
            int freq = map.find(x)->first;
            num_pos num_and_pos = map.find(x)->second;
            map.insert(pair<int, num_pos>(freq+1, num_and_pos));

        }
//        freq_count.count(x) ? freq_count.insert(pair<int, pair<int,int>>(x, (1, 2)) : freq_count.at(x) += 1;
//        stack.push_back(x);
//
//        if (multimap.at(x) >= max_freq) {
//            max_vals.push_back(x);
//            max_freq = multimap.at(x);
//        }
    }

    int pop() {
        if (max_vals.size() == 1) {

        }
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */