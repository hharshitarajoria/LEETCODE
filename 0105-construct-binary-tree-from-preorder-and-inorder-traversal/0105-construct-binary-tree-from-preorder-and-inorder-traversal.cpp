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
    TreeNode* TreeBuild(vector<int>& inorder, int inStart,int inEnd,
                        vector<int>& preorder,int preStart,int preEnd, map<int,int>& inMap){
            if(preStart> preEnd || inStart > inEnd) return NULL;

            TreeNode* root= new TreeNode(preorder[preStart]); 
            //where does root lie in inorder
            int inRoot= inMap[root->val];

            //left nodes
            int numsLeft= inRoot- inStart;

            //now make left and right part new inorder and new preorder
            root->left = TreeBuild(inorder,inStart,inRoot-1, 
                                    preorder, preStart+1, preStart+ numsLeft, inMap);
            root->right = TreeBuild(inorder,inRoot+1,inEnd, 
                                    preorder, preStart+1+numsLeft, preEnd, inMap);

            return root;
            }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //hash inorder
        map<int,int> inMap;
        for( int i=0;i<inorder.size(); i++){
            inMap[inorder[i]] = i;
            }
        TreeNode* root= TreeBuild(inorder,0,inorder.size()-1,
                                  preorder,0,preorder.size()-1, inMap);
        return root;
        }
};