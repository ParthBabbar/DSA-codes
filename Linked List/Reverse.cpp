**** recursive solution
class Solution {

ListNode* reverse1(ListNode* head){
    
    if(head==NULL || head->next == NULL){
        return head;
    }
    
    ListNode* rest = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return rest;
}
public:
ListNode* reverseList(ListNode* head) {
return reverse1(head);
}
};

****Iterative Solution
LinkedListNode *reverseLinkedList(LinkedListNode *head)
{
// Write your code here
if(head == NULL || head->next == NULL){
return head;
}

LinkedListNode<int> *prev = NULL;
LinkedListNode<int> *curr = head;
LinkedListNode<int> *forward = NULL;
while(curr != NULL){
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
}

return prev;
}
