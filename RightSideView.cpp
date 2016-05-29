struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return result;
        dfs(root, 1);
        return result;
    }

    void dfs(TreeNode* root, int depth)
    {
    	if(!root) return;
    	if(result.size() < depth)
    		result.push_back(root->val);

    	if(root->right) dfs(root->right, depth + 1);
    	if(root->left) dfs(root->left, depth + 1);
    }

private:
	vector<int> result;
};