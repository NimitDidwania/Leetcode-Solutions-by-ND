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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *prev=NULL,*head=NULL ,*c1=list1,*c2=list2;
        //list1 should be the answer
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        while(c1!=NULL && c2!=NULL)
        {
            if(c1->val > c2->val)
            {
                if(prev==NULL)
                {
                    ListNode *temp=c2->next;
                    c2->next=c1;
                    head=c2;
                    prev=c2;
                    c2=temp;
                }
                else{
                    ListNode *temp=c2->next;
                    prev->next=c2;
                    c2->next=c1;
                    prev=c2;
                    c2=temp;
                }
            }
            else{
                if(prev==NULL)
                {
                    head=c1;
                    prev=c1;
                    c1=c1->next;
                }
                else{
                    prev=c1;
                    c1=c1->next;
                }
            }
        }
        if(c2!=NULL)prev->next=c2;
        return head;
    }
};