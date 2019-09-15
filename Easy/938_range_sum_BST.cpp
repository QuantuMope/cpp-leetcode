/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /**
    Runtime: 136 ms,  Faster than 96.25%
    Memory : 41.1 MB, Less than 100.00%
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        if (root == nullptr) return sum;
        int val = root->val;
        if (val >= L && val <= R) {
            sum += val;
        }
        sum += rangeSumBST(root->left, L, R);
        sum += rangeSumBST(root->right, L, R);
        return sum;
    }

};

/**
    "Proper" Solution
    For some reason this code is slower on
    LeetCode tests, even though it get rids of
    needless recursive calls.

    Runtime: 152 ms,  Faster than 50.96%
    Memory : 41  MB,  Less than 100.00%
*/
 class Solution {
 public:
     int rangeSumBST(TreeNode* root, int L, int R) {
         int sum = 0;
         if (root == nullptr) return sum;
         int val = root->val;
         if (val >= L && val <= R) {
             sum += val;
             sum += rangeSumBST(root->left, L, R);
             sum += rangeSumBST(root->right, L, R);
         }
         else if (val >= L) {
             sum += rangeSumBST(root->left, L, R);
         }
         else {
             sum += rangeSumBST(root->right, L, R);
         }
         return sum;
     }

 };
