class Solution {
public:
    int ans = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root, 0);
        return ans;
    }
    
    void helper(TreeNode* root,int state){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            if(state)
                ans += root->val;
            return;
        }
        helper(root->left,1);
        helper(root->right,0);
    }
};