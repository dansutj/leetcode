struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return result;

        stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* pre = NULL;

        while(cur || !stk.empty())
        {
        	if(cur)
        	{
        		stk.push(cur);
        		cur = cur->left;
        	}
        	else
        	{
        		TreeNode* node = stk.top();
        		if(node->right && pre != node->right)
        			cur = node->right;

        		else
        		{
        			result.push_back(node->val);
        			pre = node;
        			stk.pop();	
        		}
        	}
        }
        return result;
    }

private:
	vector<int> result;
};