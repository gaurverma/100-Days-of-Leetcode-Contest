/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void traverse(TreeNode* root,vector <int> &vals){
        if(root==NULL)
            return;
        traverse(root->left,vals);
        vals.push_back(root->val);
        traverse(root->right,vals);
    }
    
    TreeNode* split(vector<int>& vals,int beg,int end){
        int mid = (beg+end)/2;
        TreeNode* root = new TreeNode(vals[mid]);
        if(beg==end) 
          return root;
        if(beg!=mid)
            root->left = split(vals,beg,mid-1);
        if(mid!=end)
            root->right = split(vals,mid+1,end);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector <int> vals;
        traverse(root,vals);
        TreeNode* ans = split(vals,0,vals.size()-1);
        return ans;
    }
};