/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {
        if (preStart >= preorder.size() || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int rootIndex = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == root->val) {
                rootIndex = i;
                break;
            }
        }

        root->left = buildTreeHelper(preorder, inorder, preStart + 1, inStart, rootIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, preStart + (rootIndex - inStart) + 1, rootIndex + 1, inEnd);

        return root;

    }
};
