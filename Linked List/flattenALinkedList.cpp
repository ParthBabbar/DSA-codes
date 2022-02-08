/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* sort(Node* first, Node* second)
{
    // When only one node is in first list, point its head to the second list.
    if(first -> child == NULL)
    {
        first->child = second;
        return first;
    }

    Node* cur1 = first, *next1 = first -> child;
    Node* cur2 = second, *next2 = second -> child;

    while(next1 && cur2)
    {
        if ((cur2->data) >= (cur1->data) && (cur2->data) <= (next1->data)) { 
            next2 = cur2->child; 
            cur1->child = cur2; 
            cur2->child = next1; 
  
            // Let cur1 and cur2 to point to their immediate next pointers.
            cur1 = cur2; 
            cur2 = next2; 
        } 
        else { 
            // if there are more nodes in first list.
            if (next1->child) { 
                next1 = next1->child; 
                cur1 = cur1->child; 
            } 
  
            // else point the last node of first list to the remaining nodes of second list.
            else { 
                next1->child = cur2; 
                return first; 
            } 
        } 
    }

    return first;
}

Node* merge(Node* first, Node* second) {
    if(!first)
    {
        return second;
    }
    if(!second)
    {
        return first;
    }

    if((first -> data) < (second ->data))
    {
        return sort(first, second);
    }
    else
    {
        return sort(second, first);
    }
}
    

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    if(head == NULL){
        return head;
    }
    Node* down = head;
    Node* right = flattenLinkedList(head->next);
    down->next = NULL;
    
    Node* ans = merge(down,right);
    
    return ans;
}
