/*
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0)
        return NULL;

    struct TreeNode *root = malloc(sizeof(*root));
    root->val = *preorder;
    root->left = root->right = NULL;
    if (preorderSize == 1)
        return root;

    int *p = inorder;
    while (*p != root->val) {
        p++;
    }
    int leftSize = p - inorder;
    int rightSize = inorderSize - 1 - leftSize;
    root->left = buildTree(preorder+1, leftSize, inorder, leftSize);
    root->right = buildTree(preorder+1+leftSize, rightSize, p+1, rightSize);
    return root;
}
