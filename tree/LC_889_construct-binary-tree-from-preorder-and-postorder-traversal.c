/*
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
 * If there exist multiple answers, you can return any of them.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize) {
    if (preorderSize == 0)
        return NULL;

    struct TreeNode *root = malloc(sizeof(*root));
    root->val = *preorder;
    root->left = root->right = NULL;
    if (preorderSize == 1)
        return root;

    int *p = postorder;
    while (*p != preorder[1]) {
        p++;
    }
    int leftSize = p - postorder + 1;
    int rightSize = preorderSize - 1 - leftSize;
    root->left = constructFromPrePost(preorder+1, leftSize, postorder, leftSize);
    root->right = constructFromPrePost(preorder+1+leftSize, rightSize, p+1, rightSize);
    return root;
}
