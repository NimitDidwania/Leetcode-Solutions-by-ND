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
    ListNode* reverse(ListNode* curr)
    {
        ListNode * prev=NULL;
        while(curr!=NULL)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode * curr1 = head;ListNode * curr2 = head , *curr = head;
        if(head==NULL)return head;
        while(curr!=NULL)
        {
            n++;curr=curr->next;
        }cout<<n<<endl;
        k = k%n;
        if(k==0)return head;
        cout<<"c";
        curr1=head;
        int i=0;
        while(i<n-k)
        {
            curr2=curr2->next;i++;
        }
        cout<<curr2->val;
        ListNode *prev=NULL ;curr=head;
        while(curr!=curr2)
        {
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        ListNode *pre = NULL;
         while(curr2!=NULL)
        {
            ListNode*temp=curr2->next;
            curr2->next=pre;
            pre=curr2;
            curr2=temp;
        }
        
        head->next=pre;
        return reverse(prev);
    }
};