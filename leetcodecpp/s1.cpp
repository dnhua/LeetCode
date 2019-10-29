
#include "pch.h"
using namespace std;

int run(TreeNode *root) {
	if (root == NULL)
		return 0;
	int left = run(root->left);
	int right = run(root->right);
	if (left == 0 || right == 0)
		return left + right + 1;
	return min(left, right) + 1;
}