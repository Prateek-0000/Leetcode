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
    int ans = 0;

    vector<int> solve(TreeNode* root) {
        if(root == NULL)
            return {1, INT_MAX, INT_MIN, 0};

        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);


        if(left[0] && right[0] &&
           left[2] < root->val && root->val < right[1]) {

            int sum = left[3] + right[3] + root->val;

            ans = max(ans, sum);

            int mn = min(left[1], root->val);
            int mx = max(right[2], root->val);

            return {1, mn, mx, sum};
        }

        return {0, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};