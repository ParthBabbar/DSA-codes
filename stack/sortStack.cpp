void sortInsert(stack<int> &stack,int val){
    //base case
    if((!stack.empty() && val>stack.top()) || stack.empty()){
        stack.push(val);
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    //recursive call
    sortInsert(stack,val);
    
    stack.push(num);
    
}

void sortStack(stack<int> &stack)
{
	// base case
    if(stack.empty()){
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    //recursive call
    sortStack(stack);
    
    sortInsert(stack,num);
}
