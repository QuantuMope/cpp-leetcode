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
         bool t_det {false};
         bool f_det {false};
         char op = input[0];
         for (auto &c : input) {
             if (t_det && f_det) break;
             if (c == 't') t_det = true;
             else if (c == 'f') f_det = true;
         }
         if (input.find('t') != string::npos) t_det = true;
         if (input.find('f') != string::npos) f_det = true;
         // ! Case
         if (op == '!' && t_det) return "f";
         else if(op == '!') return "t";

         // & Case
         if (op == '&' && f_det) return "f";
         else if (op == '&') return "t";

         // | Case
         if (op == '|' && t_det) return "t";
         else if (op == '|') return "f";

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
        int counter {1};
        for (auto &paran : paran_pos) {
            int start {paran.first-1};
            int end {paran.second - paran.first + 2};
            expression.replace(start, end,
                               simplifyBool(expression.substr(start, end)));
            for (int i = counter; i < paran_pos.size(); i++) {
                if (paran_pos[i].first < start) paran_pos[i].second -= end -1;
                else {
                    paran_pos[i].first -= end - 1;
                    paran_pos[i].second -= end -1;
                }
            }
            counter++;
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