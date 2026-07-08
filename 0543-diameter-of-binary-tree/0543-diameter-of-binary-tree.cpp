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
    int maxi=0;
    int height(TreeNode* node){
        if(node==NULL) return 0;

        int lh=height(node->left);
        int rh=height(node->right);

        return 1+ max(lh,rh);
    }
     void findmax(TreeNode* root) {
        if(root==NULL) return ;
        int lh=height(root->left);
        int rh= height(root->right);
        maxi=max(maxi,lh+rh);

        findmax(root->left);
        findmax(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root){
        findmax(root);
        return maxi;
    }
};