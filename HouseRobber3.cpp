struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        vector<int> nums = dfs(root);
        return max(nums[0], nums[1]);
    }

    vector<int> dfs(TreeNode* root)
    {
    	if(!root) return vector<int>(2);

    	vector<int> left = dfs(root->left);
    	vector<int> right = dfs(root->right);

    	vector<int> nums(2);
    	nums[0] = left[1] + right[1] + root->val;
    	nums[1] = max(left[0], left[1]) + max(right[0], right[1]);
    	return nums;
    }
};