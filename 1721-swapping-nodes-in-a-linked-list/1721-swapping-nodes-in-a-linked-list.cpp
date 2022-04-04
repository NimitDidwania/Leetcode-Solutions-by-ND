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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*curr=head;int n=0;
        while(curr!=NULL){
            curr=curr->next;
            n++;
        }
        int l=n-k+1;
        int i=1;
        ListNode*a=head,*b=head;
        while(i<k){
            a=a->next;
            i++;
        }
         i=1;
        while(i<l){
            b=b->next;
            i++;
        }
        swap(a->val,b->val);
        return head;
    }
};