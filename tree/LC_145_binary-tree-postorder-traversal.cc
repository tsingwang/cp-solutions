/*
 * https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *cur = root;
        TreeNode *last = NULL;

        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            TreeNode *t = s.top();
            if (t->right && last != t->right) {
                cur = t->right;
            } else {
                res.push_back(t->val);
                s.pop();
                last = t;
            }
        }
        return res;
    }
};
