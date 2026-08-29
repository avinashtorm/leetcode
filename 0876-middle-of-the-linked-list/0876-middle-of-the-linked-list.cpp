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
    ListNode* middleNode(ListNode* head) {
        ListNode* t1=head;
        ListNode* t2=head;
        ListNode* t0;
        int c=0;
        while(t2){
            t0=t1;
            t1=t1->next;
            if(t2->next)t2=t2->next->next;
            else{
                t2=t2->next;
                c++;
            } 
        }
        if(c==1)return t0;
        return t1;
    }
};