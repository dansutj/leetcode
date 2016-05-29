struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return result;

        TreeNode* pre = NULL;
        TreeNode* cur = root;

        while(cur)
        {
        	if(!cur->left)
        	{
        		result.push_back(cur->val);
        		cur = cur->right;
        	}
        	else
        	{
        		pre = cur->left;
        		while(pre->right && pre->right != cur)
        			pre = pre->right;

        		if(!pre->right)
        		{
        			pre->right = cur;
        			cur = cur->left;
        		}
        		else 
        		{
        			result.push_back(cur->val);
        			pre->right = NULL;
        			cur = cur->right;
        		}
        	}
        }
        return result;
    }

private:
	vector<int> result;
};