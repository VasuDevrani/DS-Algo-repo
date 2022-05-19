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

   bool valid(TreeNode* root, TreeNode* minnode, TreeNode* maxnode){
        if(root == NULL)
            return true;
        
        if(minnode != NULL && root->val <= minnode->val)
            return false;
        if(maxnode != NULL && root->val >= maxnode->val)
            return false;
        
        bool l = valid(root->left, minnode, root);
        bool r = valid(root->right, root, maxnode);
        
        return l && r;
    }

    bool isValidBST(TreeNode* root) {
        return valid(root, NULL, NULL);
    }
};