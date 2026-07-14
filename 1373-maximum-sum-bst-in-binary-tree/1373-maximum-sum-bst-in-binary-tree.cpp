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
class NodeValue {
public:
    int maxNode, minNode, sum;
    NodeValue(int minNode, int maxNode, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};
class Solution {
public:
    int ans = 0;
    NodeValue helper(TreeNode* root) {
        if (root == NULL) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        auto left = helper(root->left);
        auto right = helper(root->right);
        if (left.maxNode < root->val &&
            root->val < right.minNode) {
            int currSum =left.sum +right.sum +root->val;
            ans = max(ans, currSum);
            return NodeValue(min(left.minNode, root->val),max(right.maxNode, root->val),currSum
            );
        }
        return NodeValue(INT_MIN,INT_MAX,0);
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};