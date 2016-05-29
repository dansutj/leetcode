struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        dfs(root);

        return maxPath == INT_MIN ? 0 : maxPath;
    }

    int dfs(TreeNode* root)
    {
    	if(!root) return 0;

    	int left = root->left ? dfs(root->left) : 0;
    	int right = root->right ? dfs(root->right) : 0;

    	left = left < 0 ? 0 : left;
    	right = right < 0 ? 0 : right;

    	maxPath = max(maxPath, root->val + left + right);
    	return max(left, right) + root->val;
    }

private:
	int maxPath = INT_MIN;
};