#include <string>
#include <iostream>

using namespace std;

class Solution {
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

int main() {

    Solution test;
    bool outcome = test.parseBoolExpr("|(&(t,f,t),!(t))");
    cout << boolalpha << outcome << endl;
    return 0;
}