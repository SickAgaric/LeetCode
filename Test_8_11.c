struct TreeNode* sort(struct TreeNode* root, int *nums, int numsSize);
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode* root;
    return sort(root, nums, numsSize);
}
struct TreeNode* sort(struct TreeNode* root, int *nums, int numsSize)
{
    root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (numsSize == 0)
        return NULL;
    if (numsSize % 2 == 0)
    {
        numsSize /= 2;
        root->val = nums[numsSize];
        root->left = sort(root->left, nums, numsSize);
        root->right = sort(root->right, nums + numsSize + 1, numsSize - 1);
    }
    else
    {
        numsSize /= 2;
        root->val = nums[numsSize];
        root->left = sort(root->left, nums, numsSize);
        root->right = sort(root->right, nums + numsSize + 1, numsSize);
    }
    return root;
}