struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    void recoverTree(TreeNode* root) {
        pre = first = second = NULL;

        inorder(root);

        if(first)
        {
        	int temp = second->val;
        	second->val = first->val;
        	first->val = temp;
        }
    }

private:
	TreeNode *pre, *first, *second;

	void inorder(TreeNode* root)
	{
		if(!root) 
			return;

		if(root->left) 
			inorder(root->left);

		if(pre && pre->val > root->val)
		{
			if(!first) first = pre;
			second = root;
		}

		pre = root;

		if(root->right)
			inorder(root->right);
	}
};