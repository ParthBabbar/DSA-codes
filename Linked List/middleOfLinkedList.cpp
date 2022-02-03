****Optimal approach
class Solution {
public:
ListNode* middleNode(ListNode* head) {

    //if head is null or 1 node return head
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    //if list has 2 nodes
    if(head->next->next == NULL){
        return head->next;
    }
    
    // taking 2 nodes fast and slow and slower node will be our ans
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while(fast != NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        
        slow = slow->next;
    }
    
    return slow;
}
};

****Basic Approach
int getlength(Node *head){
int len = 0;
while(head!=0){
head = head->next;
len++;
}
return len;
}

Node *findMiddle(Node *head) {

int len = getlength(head);

int ans = (len/2) + 1;
int cnt = 1;
Node* temp = head;
while(cnt<ans){
    temp = temp->next;
    cnt++;
}

return temp;
}
