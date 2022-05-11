class Solution {
public:
    typedef pair<int,int> pi;
    int ans  = 0;
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
    pair<int,int> helper(TreeNode* root){
        if(root==NULL)
            return {0,0};
        pi left = helper(root->left);
        pi right = helper(root->right);
        int sum = left.first+right.first+root->val;
        int nume = left.second+right.second+1;
        if(sum/nume == root->val)
            ans++;
        return {sum,nume};
    }
};