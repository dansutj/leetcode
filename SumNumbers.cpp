struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode* root, int path)
    {
    	if(!root) return;
    	path = path * 10 + root->val;

    	if(root->left) dfs(root->left, path);
    	if(root->right) dfs(root->right, path);
    	if(!root->left && !root->right)
    		 sum += path;
    }

private:
	int sum = 0;
};