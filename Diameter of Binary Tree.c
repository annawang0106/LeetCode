/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(root==NULL) return 0;               //邊界條件

    int leftDepth = maxDepth(root->left);  //算左邊的高度
    int rightDepth = maxDepth(root->right);//算右邊的高度
    int max = leftDepth;                   //比較左右兩邊高度，取最高
    if (rightDepth>max){
        max = rightDepth;
    }
    return max + 1;                        //+1是root高度
}

int diameterOfBinaryTree(struct TreeNode* root){
    if(root == NULL) return 0;              //邊界條件  
    int middle = maxDepth(root->left)+maxDepth(root->right);
    int left = diameterOfBinaryTree(root->left);
    int right = diameterOfBinaryTree(root->right);
    int max = middle;
    if (left > max){
        max = left;
    }else if (right>max){
        max = right;
    }
    return max;
}
