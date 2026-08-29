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
    ListNode* reverseList(ListNode* head) {
        if(!head)return nullptr;
        ListNode* t0=head;
        ListNode* t1;
        ListNode* t=head->next;
        while(t){
            t1=t->next;
            t->next=t0;
            t0=t;
            t=t1;
        }
        head->next=nullptr;
        return t0;
    }
};