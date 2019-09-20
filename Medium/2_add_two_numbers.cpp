/**
 * This is a very trivial challenge.
 *
 * Time Complexity: O(N) where N is the number of total nodes
 *                  Faster for cases where integer overflow is not a problem
 *
 * Use of strings seems to have poor memory efficiency
 * Runtime: 24 ms, Faster than 63.55%
 * Memory: 10.5 MB, Less than 21.14%
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    // Helper function to convert Linked List into string of int vals
    string listNodeToString(ListNode *l) {
        string output;
        while (l != nullptr) {
            output += l->val + '0';
            l = l->next;
        }
        return output;
    }

    // Helper function to add strings if integer overflow is a problem
    string intOverflow(string &first, string &second) {
        if (first.size() < second.size()) {
            string temp = first;
            first = second;
            second = temp;
        }
        second += string(first.size()-second.size(), '0');
        string sum;
        int add {0};
        int ten_carry_over {0};
        for (int i = 0; i < first.size(); i++) {
            add = (first[i] - '0') + (second[i] - '0') + ten_carry_over;
            if (add >= 10) ten_carry_over = 1;
            else           ten_carry_over = 0;
            sum += (add % 10) + '0';
            if (i == first.size()-1 && ten_carry_over == 1) sum += '1';
        }
        return sum;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string first = listNodeToString(l1);
        string second = listNodeToString(l2);
        string sum;

        // Case 1: Integer Overflow
        // Adds ints char by char.
        if (first.size() > 9 || second.size() > 9) {
            sum = intOverflow(first, second);
        }

        // Case 2: No Integer Overflow
        // Reverse strings and convert straight into int and add together
        // Convert to string and reverse again
        else {
            reverse(first.begin(), first.end());
            reverse(second.begin(), second.end());
            // stoi does not work in leetcode
            int add = atoi(first.c_str()) + atoi(second.c_str());
            sum  = to_string(add);
            reverse(sum.begin(), sum.end());
        }


        // Converting string into Linked List
        ListNode *add_ptr = new ListNode(sum[0] - '0');
        ListNode *first_ptr {add_ptr};
        for (int i = 1; i < sum.size(); i++) {
            add_ptr->next = new ListNode(sum[i] - '0');
            add_ptr = add_ptr->next;
        }
        return first_ptr;
    }
};
