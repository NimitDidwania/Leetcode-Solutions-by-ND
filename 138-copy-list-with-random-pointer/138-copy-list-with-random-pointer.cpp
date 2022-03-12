/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        Node* curr=head;
        while(curr!=    NULL)
        {
            Node* currNext  = new Node(curr->val);
            Node* temp= curr->next;
            curr->next=currNext;
            currNext->next=temp;
            curr=temp;
        }
        curr=head;
       
        while(curr!=NULL)
        {
            if(curr->random!=NULL)
            curr->next->random=curr->random->next;
            else curr->next->random=NULL;
            curr=curr->next->next;
        }
        curr=head;
        Node*cpyHead=head->next;
        while(curr!=NULL)
        {
            Node*temp=curr->next;
            if(curr->next!=NULL)
            curr->next=curr->next->next;
            else curr->next=NULL;
            curr=temp;
        }
        
        
        return cpyHead;
    }
};