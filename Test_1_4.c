class Solution {
public:
    void Mirror(TreeNode *pRoot) {
   if(pRoot==NULL)
       return;
   if(pRoot->left==NULL&&pRoot->right==NULL)
       return;
   TreeNode*pTmp=pRoot->left;
   pRoot->left=pRoot->right;
   pRoot->right=pTmp;
   if(pRoot->left!=NULL)
     Mirror(pRoot->left);
   if(pRoot->right!=NULL)
     Mirror(pRoot->right);
    }
};