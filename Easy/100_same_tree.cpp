/**
 * Although verbose, the algorithm is very fast.
 * Depth first search through recursive calls.
 *
 * Time Complexity: O(N) where N is nodes of Tree p/q
 *
 * Runtime: 0 ms, Faster than 100.00%
 * Memory: 9.7 MB, Less than 100.00%
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        else if(p == NULL || q == NULL) return false;

        bool left {true};
        bool right {true};
        if (p->val == q->val){
            if ((p->left == NULL && q->left == NULL) && (p->right != NULL && q->right != NULL)) {
                right = isSameTree(p->right, q->right);
            }
            else if ((p->left != NULL && q->left != NULL) && (p->right == NULL && q->right == NULL)) {
                left = isSameTree(p->left, q->left);
            }
            else if (p->left != NULL && p->right != NULL && q->left != NULL && q->right != NULL) {
                left = isSameTree(p->left, q->left);
                right = isSameTree(p->right, q->right);
            }
            else if (p->left == NULL && p->right == NULL && q->left == NULL && q->right == NULL) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
        return left && right;
    }
};