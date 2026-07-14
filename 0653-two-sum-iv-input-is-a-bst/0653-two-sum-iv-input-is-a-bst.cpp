/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse;
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    void pushAll(TreeNode* root) {
        while (root != NULL) {
            st.push(root);
            if (reverse)
                root = root->right;
            else
                root = root->left;
        }
    }
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if (reverse)
            pushAll(temp->left);
        else
            pushAll(temp->right);
        return temp->val;
    }
    bool hasNext() {
        return !st.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL)
            return false;
        BSTIterator left(root, false);   // Inorder iterator
        BSTIterator right(root, true);   // Reverse inorder iterator
        int i = left.next();
        int j = right.next();
        while (i < j) {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = left.next();
            else
                j = right.next();
        }
        return false;
    }
};