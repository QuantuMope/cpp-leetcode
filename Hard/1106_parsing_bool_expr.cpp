#include <string>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution1 {
public:

    string simplifyBool(char op, const int &t_det, const int &f_det) {
        // ! Case
        if (op == '!' && t_det > 0) return "f";
        else if(op == '!') return "t";

        // & Case
        if (op == '&' && f_det > 0) return "f";
        else if (op == '&') return "t";

        // | Case
        if (op == '|' && t_det > 0) return "t";
        else if (op == '|' && t_det == 0) return "f";

        return "0";
    }

    string partition(string input) {
        int t_det {0};
        int f_det {0};

        if (input.size() <= 1) return input;

        string output {""};
        int back_paran = 0, front_pos = 0, back_pos = 0;
        int counter {-1};
        for (auto &c : input) {
            counter++;
            if (c == ')') {
                back_paran++;
                back_pos = counter;
            } else if (c == '(') {
                front_pos = counter;
                t_det = f_det = 0;
            } else if (c == 't') {
                t_det++;
            } else if (c == 'f') {
                f_det++;
            }

            if (back_paran > 0) break;
        }
        front_pos--;
        output += partition(input.substr(0, front_pos) +
                            simplifyBool(input[front_pos], t_det, f_det) +
                            input.substr(back_pos + 1));
        return output;
    }

    bool parseBoolExpr(string expression) {
        string simp = partition(expression);
        if (simp.find('f') != string::npos) return false;
        return true;
    }
};


class Solution {
public:

    string simplifyBool(string input) {
         int t_det {0};
         int f_det {0};
         char op = input[0];
         string f(input.size(), 'f');
         string t(input.size(), 't');
         for (auto &c : input) {
             if (t_det > 0 && f_det > 0) break;
             if (c == 't') t_det++;
             else if (c == 'f') f_det++;
         }
         // ! Case
         if (op == '!' && t_det > 0) return f;
         else if(op == '!') return t;

         // & Case
         if (op == '&' && f_det > 0) return f;
         else if (op == '&') return t;

         // | Case
         if (op == '|' && t_det > 0) return t;
         else if (op == '|' && t_det == 0) return f;

         return "0";
    }
    bool parseBoolExpr(string expression) {
        stack<int> front_paran;
        vector<pair<int, int>> paran_pos;
        int index {0};
        while (index < expression.size()) {
            if (expression[index] == '(') front_paran.push(index);
            else if (expression[index] == ')') {
                paran_pos.push_back(pair<int, int>(front_paran.top(), index));
                front_paran.pop();
            }
            index++;
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

    Solution test;
    bool outcome = test.parseBoolExpr("!(&(!(t),&(f),|(f)))");
    cout << boolalpha << outcome << endl;
    return 0;
}