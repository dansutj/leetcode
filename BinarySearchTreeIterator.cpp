struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if(root) pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = stk.top();
        stk.pop();

        pushAll(node->right);
        return node->val;
    }

private:
	stack<TreeNode*> stk;

	void pushAll(TreeNode* root)
	{
		if(!root) return;

		TreeNode* node = root;
		while(node)
		{
			stk.push(node);
			node = node->left;
		}
	}
};