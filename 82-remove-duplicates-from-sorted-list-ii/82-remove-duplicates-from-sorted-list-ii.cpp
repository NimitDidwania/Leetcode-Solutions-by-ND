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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*dumHead=new ListNode(-101);
        dumHead->next=head;
        ListNode* curr=head ,*prev=dumHead;
        int preVal=-101;
        while(curr!=NULL){
            if(curr->val==preVal || (curr->next!=NULL&&curr->val==curr->next->val))
            {
                prev->next=curr->next;
                preVal=curr->val;
                ListNode *temp=curr;
                curr=curr->next;
                delete temp;
            }
            else {prev=curr;preVal=curr->val;curr=curr->next;}
                
        }
        return dumHead->next;
        
        }
};