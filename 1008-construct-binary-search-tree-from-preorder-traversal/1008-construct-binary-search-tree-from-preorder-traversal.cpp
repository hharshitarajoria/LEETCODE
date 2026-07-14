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
    TreeNode* buildBST(vector<int>& preorder, int &ptr,int bound){
        if(ptr==preorder.size() || preorder[ptr] > bound) return NULL;
        TreeNode* root= new TreeNode(preorder[ptr++]);
        root->left = buildBST(preorder, ptr, root->val);
        root->right = buildBST(preorder, ptr, bound);
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ptr = 0;
        return buildBST(preorder,ptr,INT_MAX); 
    }
};