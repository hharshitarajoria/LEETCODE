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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL || root==p ||root==q) // reach any of the given node
         return root; 
        
        TreeNode* left=  lowestCommonAncestor(root->left, p, q) ;
        TreeNode* right=  lowestCommonAncestor(root->right, p, q) ;

        if(left==NULL ) return right;
        else if(right==NULL) return left;
        else //when both left and right is null
            return root;
    }
};