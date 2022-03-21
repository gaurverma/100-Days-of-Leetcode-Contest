class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* list1aprev,*list1bnext;
        ListNode* list2end;
        ListNode* curr  = list1;
        int  i = 0;
        while(curr){
            if(i==a-1)
                list1aprev = curr;
            if(i==b+1)
                list1bnext = curr;
            curr = curr->next;
            i++;
        }
        curr = list2;
        while(curr->next){
            curr = curr->next;
        }
        list2end = curr;
        
        list1aprev->next = list2;
        list2end->next = list1bnext;
        return list1;
    }
};