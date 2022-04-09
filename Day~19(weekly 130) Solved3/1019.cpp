/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector <int> ans;
    stack <int> s;
    void helper(ListNode *head){
        if(head==NULL)
            return;
        helper(head->next);
        while(!s.empty() && s.top()<=head->val)
            s.pop();
        if(s.empty()) ans.push_back(0);
        else ans.push_back(s.top());
        s.push(head->val);
        return;
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        helper(head);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};