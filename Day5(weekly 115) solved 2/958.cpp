class Solution {
public:
    
    
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)
             return 0;
        
        queue <TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            int count  = q.size();
            while(count--){
                TreeNode * front = q.front();
                q.pop();
                if(front == NULL){
                    flag = true;
                    continue;
                }else if(flag)
                    return false;
                q.push(front->left);
                q.push(front->right);
              
            }
        }
        
        return true;
    }
};