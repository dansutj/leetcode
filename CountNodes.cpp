struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int countNodes(TreeNode* root) {
		if(!root) return 0;

		TreeNode* left = root;
		TreeNode* right = root;
		int lh = rh = 0;

		while(left)
		{
			left = left->left;
			++lh;
		}

		while(right)
		{
			right = right->right;
			++rh;
		}

		if(lh == rh) return (1 << lh) - 1;
		else return 1 + countNodes(root->left) + countNodes(root->right);
    }

};