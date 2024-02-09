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
    int length_LL(ListNode *head)
    {   
        // this function is for getting the length of LL
        if(head==NULL) // if head is NULL then the length of LL is 0
            return 0;
        int count=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* reverse(ListNode*head,int k)
    {
        // this function is for reverse k node
        int count=0;
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *forward;
        while(curr!=NULL && count<k)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) 
    {   
        if(head==NULL)
            return NULL;
        int len=length_LL(head);
        k=k%len;            // if k is greater than length
        if(k==0)            // if k is 0 then you have to return head
            return head;
        head=reverse(head,len);     //reverse full linked list
        ListNode *ptr1=head;        //this pointer is for the containing remaining part head from starting to k position
        ListNode *temp_head=NULL;  
        int count=0;                //this is for count the starting k node
        while(count<k)
        {
            ptr1=ptr1->next;        //traverse the ptr1 pointer
            count++;
        }                           // ptr1 has the staring (k+1)th number node addess
        temp_head=reverse(head,k);       // temp_head has the reverse linked list head
        // temp_head has the head of the reverse linked list and head is the pointing the kth node because now linked list is reversed 
        swap(temp_head,head);                // swap the both pointer now temp_head is the pointing the kth node
        temp_head->next=reverse(ptr1,len);   // reverse the ramining (length-k) nodes 
        return head;
    }
};