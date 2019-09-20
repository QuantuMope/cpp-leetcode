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

    int listNodeToInt(ListNode *l) {
        string output;
        while (l != nullptr) {
            output += l->val + '0';
            l = l->next;
        }
        reverse(output.begin(), output.end());
        cout << output << endl;
        return atoi(output.c_str());
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string sum = to_string(listNodeToInt(l1) + listNodeToInt(l2));
        cout << sum << endl;
        reverse(sum.begin(), sum.end());
        ListNode *add_ptr = new ListNode(sum[0] - '0');
        ListNode *first_ptr {add_ptr};
        for (int i = 1; i < sum.size(); i++) {
            add_ptr->next = new ListNode(sum[i] - '0');
            add_ptr = add_ptr->next;
        }
        return first_ptr;
    }
};