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
void r(ListNode* &back,ListNode* &front,ListNode* &newhead){
    if(!front){
        newhead=back;
        return;
    }
    if(front->next){
        r(back->next,front->next,newhead);
    }else newhead=front;
    front->next=back;
}
    ListNode* reverseList(ListNode* head) {
        if(!head)return nullptr;
        ListNode* t=head;
        ListNode* newhead=nullptr;
        r(t,t->next,newhead);
        head->next=nullptr;
        return newhead;
    }
};