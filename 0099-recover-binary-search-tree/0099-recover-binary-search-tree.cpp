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
private:
    TreeNode* prev;
    TreeNode* last;
    TreeNode* first;
    TreeNode* middle;

    void inorder(TreeNode* root){
        if(root == NULL) return;
        
        inorder(root->left);

        if(prev != NULL && (prev->val > root->val)){
            //first violation
            if(first==NULL){
                first=prev;
                middle=root;
            }
            //second violation
            else{
                last=root;
            }
        }
        prev=root; //mark current node as prev
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN); // first node in BST is always smallest
        inorder(root);
        if(first && last) swap(first->val, last->val); //nodes are not adjacent
        else if(first && middle) swap(first->val, middle->val);
    }
};