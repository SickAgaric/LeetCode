

typedef struct TreeNode TreeNode;

int Getsize(TreeNode* root)
{
    if(root==NULL)
        return 0;
    return Getsize(root->left)+Getsize(root->right)+1;
}

void CopyTree(TreeNode* root,int* newarr,int* len)
{
    if(root==NULL)
        return;
    
    
    
    printf("\n");

    CopyTree(root->left,newarr,len);
    
    printf("\n");

    
    newarr[*len] = root->val;
    (*len)++;

    CopyTree(root->right,newarr,len);
    


}
int* inorderTraversal(struct TreeNode* root, int* returnSize){

    *returnSize = Getsize(root);
    int* newarr = (int*)malloc(sizeof(int)**returnSize);
    if(root==NULL)
        return newarr;
    int i = 0;
    CopyTree(root,newarr,&i);
    
    return newarr;
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p==NULL&&q==NULL)
        return true;
    
    if(p==NULL||q==NULL)
        return false;
    
    if(p->val!=q->val)
        return false;
    
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){

    if(root==NULL)
        return NULL;
    
    int leftDepth = maxDepth(root->left);
    printf("A%d",leftDepth);
    int rightDepth = maxDepth(root->right);
    printf("B%d",rightDepth);

    return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
    /*return maxDepth(root->left)+0>maxDepth(root->right)+0?maxDepth(root->left)+1:maxDepth(root->right)+1;*/
    
    
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode*s,struct TreeNode* t)
{
    if(s==NULL&&t==NULL)
        return true;
    if(s==NULL||t==NULL)
        return false;
    if(s->val!=t->val)
        return false;
    
    return isSameTree(s->left,t->left)&&isSameTree(s->right,t->right);
}


bool isSubtree(struct TreeNode* s, struct TreeNode* t){

    if(s==NULL)
        return false;
    
    if(s->val==t->val)
    {
        if(isSameTree(s,t))
            return true;
    }
    
    return isSubtree(s->left,t)||isSubtree(s->right,t);
    

    
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root,int* num){

    if(root==NULL)
        return NULL;
    
    int leftDepth = maxDepth(root->left,num);
    int rightDepth = maxDepth(root->right,num);
    if(abs(leftDepth-rightDepth)>1)
    {
        *num = abs(leftDepth-rightDepth);
    }

    return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
    /*return maxDepth(root->left)+0>maxDepth(root->right)+0?maxDepth(root->left)+1:maxDepth(root->right)+1;*/ 
}

bool isBalanced(struct TreeNode* root){
    int num = 0;
    maxDepth(root,&num);
    return num<2;
    
    
        
    
}


