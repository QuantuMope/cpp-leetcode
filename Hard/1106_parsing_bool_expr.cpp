#include <string>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * Time Complexity: On average O(N) where N is length of string
 *                  Absolute worst case is O(N**2) but only happens in
 *                  certain string patterns such as continuous hugging
 *                  parans: e.g. (((((((((((())))))))))))
 *
 * Runtime: 12 ms, Faster than 49.26%
 * Memory: 15.6 MB, (not ranked)
 */
class Solution {
public:

    string simplifyBool(string input) {
        bool t_det {false};
        bool f_det {false};
        char op = input[0];
        string f(input.size(), 'f');
        string t(input.size(), 't');
        for (auto &c : input) {
            if (t_det && f_det) break;
            if (c == 't') t_det = true;
            else if (c == 'f') f_det = true;
        }
        // ! Case
        if (op == '!' && t_det) return f;
        else if(op == '!') return t;

        // & Case
        if (op == '&' && f_det) return f;
        else if (op == '&') return t;

        // | Case
        if (op == '|' && t_det) return t;
        else if (op == '|' && !t_det) return f;

        return "0";
    }
    bool parseBoolExpr(string expression) {
        stack<int> front_paran;
        vector<pair<int, int>> paran_pos;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '(') front_paran.push(i);
            else if (expression[i] == ')') {
                paran_pos.push_back(pair<int, int>(front_paran.top(), i));
                front_paran.pop();
            }
        }
        for (auto &paran : paran_pos) {
            int start {paran.first-1};
            int end {paran.second - paran.first+1};
            expression.replace(start, end,
                               simplifyBool(expression.substr(start, end)));
        }

        return expression.find('t') != string::npos;
    }
};


int main() {
    // Should be True
    Solution test;
    bool outcome = test.parseBoolExpr("!(&(!(t),&(f),|(f)))");
    cout << boolalpha << outcome << endl;
    return 0;
}