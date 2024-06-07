/*
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (postorderSize == 0)
        return NULL;

    struct TreeNode *root = malloc(sizeof(*root));
    root->val = *(postorder + postorderSize - 1);
    root->left = root->right = NULL;
    if (postorderSize == 1)
        return root;

    int *p = inorder;
    while (*p != root->val) {
        p++;
    }
    int leftSize = p - inorder;
    int rightSize = inorderSize - 1 - leftSize;
    root->left = buildTree(inorder, leftSize, postorder, leftSize);
    root->right = buildTree(p+1, rightSize, postorder+leftSize, rightSize);
    return root;
}
