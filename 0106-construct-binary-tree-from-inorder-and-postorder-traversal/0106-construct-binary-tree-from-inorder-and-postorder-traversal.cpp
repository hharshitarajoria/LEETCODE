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
    TreeNode* Treebuild(vector<int>& inorder,int inStart,int inEnd,
                        vector<int>& postorder,int postStart,int postEnd,map<int,int> & inMap){
        if(inStart> inEnd || postStart<postEnd) return NULL;

        TreeNode* root= new TreeNode(postorder[postStart]);
        int inRoot = inMap[root->val];
        int numsRight= inEnd - inRoot;

        root->left = Treebuild(inorder,inStart,inRoot-1,postorder,postStart-numsRight-1,postEnd, inMap);
        root->right= Treebuild(inorder,inRoot+1,inEnd,postorder,postStart-1,postStart-numsRight, inMap);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inMap;
        for( int i=0;i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        } 
        TreeNode* root= Treebuild(inorder,0,inorder.size()-1, postorder, postorder.size()-1,0, inMap);
        return root;    
    }
};