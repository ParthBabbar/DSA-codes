#include<stack>
int findMinimumCost(string str) {
    // string length1 is odd then no soln return -1
    if(str.length()%2 == 1){
        return -1;
    }
    stack<char> s;
    
    //remove valid part 
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        if(ch == '{'){
            s.push(ch);
        }
        else{
            //ch is closed bracket
            if(!s.empty() && s.top() == '{'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }
    
    // invalid part in stack
    int a=0, b=0;
    while(!s.empty()){
        if(s.top() == '{'){
            b++;
        }
        else{
            a++;
        }
        s.pop();
    }
    
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}
