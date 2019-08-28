int root_pathSum(struct TreeNode* root, int sum) 
{
	if (root == NULL)
	{
		return 0;
	}
	else if (root->val == sum)
	{
		return 1 + root_pathSum(root->left, 0) + root_pathSum(root->right, 0);
	}
	else
	{
		return root_pathSum(root->left, sum-root->val) + root_pathSum(root->right, sum-root->val) ;
	}
}
int pathSum(struct TreeNode* root, int sum)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return root_pathSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}
}