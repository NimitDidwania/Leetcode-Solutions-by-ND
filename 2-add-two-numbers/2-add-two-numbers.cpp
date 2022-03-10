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
    ListNode* reverse(ListNode *curr)
    {
        ListNode* prev=NULL;
        while(curr!=NULL)
        {
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *p , *q ,* P ,*Q;
        p=l1;q=l2;
        P=p,Q=q;
        ListNode*cu=p;
        ListNode *car;
        while(p!=NULL&&q!=NULL)
        {
            p->val +=( q->val+carry);
            carry=p->val/10;
            p->val%=10;
            q->val=p->val;
            if(p->next==NULL)car=p;
            p=p->next;q=q->next;
        }
        if(p!=NULL){
        while(p!=NULL)
        {
            p->val+=carry;
            carry=p->val/10;
            p->val%=10;
            if(p->next==NULL)car=p;
            p=p->next;
            
        }
            if(carry!=0){
                car->next=new ListNode(carry);
            }
           return P;
        }
        if(q!=NULL){
        while(q!=NULL){
            q->val+=carry;
            carry=q->val/10;
            q->val%=10;
             if(q->next==NULL)car=q;
            q=q->next;
           
        }
            if(carry!=0)car->next=new ListNode(carry);
            return Q;
        }
        if(carry!=0)car->next=new ListNode(carry);
        return P;
    }
};