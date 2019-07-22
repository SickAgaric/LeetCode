



/*typedef struct TreeNode TreeNode;

int arrsize(TreeNode* root)
{
    if(root==NULL)
        return 1;
    
    
    return arrsize(root->left)+1;
    return arrsize(root->right)+1;
}

int* copyNode(TreeNode* root,int* arr,int* returnSize)
{
    if(root==NULL)
        return ;
    *(arr+*(returnSize)) = root->val;
    *returnSize = *(returnSize)+1;
    
    copyNode(root->left,arr,returnSize);
    copyNode(root->right,arr,returnSize);
    
    
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* arr = (int*)malloc(sizeof(int)*arrsize);
    *returnSize = 0;
    if(root==NULL)
        return arr;
    copyNode(root,arr,returnSize);
    

    return arr;
}*/

/*int length = 0;
int* get_val = NULL;
void add_val(struct TreeNode* root)
{
    length++;
    get_val = (int*)realloc(get_val,sizeof(int)*length);
    get_val[length-1] = root->val;
}
void pre(struct TreeNode* root)
{
    if(root==NULL)
        return;
    
    add_val(root);
    pre(root->left);
    pre(root->right);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    if(root==NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    get_val = malloc(sizeof(int)*1);
    length = 1;
    get_val[0] = root->val;
    
    pre(root->left);
    pre(root->right);
    *returnSize = length;
    return get_val;
    

}*/

int getsize(struct TreeNode* root)
{
    if(root==NULL)
        return 0;
    return getsize(root->left)+getsize(root->right)+1;
}

void copyTree(struct TreeNode* root,int* newarr,int* len)
{
    if(root==NULL)
        return newarr;
    
    newarr[*len] = root->val;
    (*len)++;
    
    copyTree(root->left,newarr,len);
    copyTree(root->right,newarr,len);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = getsize(root);
    int* newarr = (int*)malloc(sizeof(int)**returnSize);
    if(root==NULL)
        return newarr;
    int len = 0;
    
    
    copyTree(root,newarr,&len);
    
    
    
    return newarr;
}


