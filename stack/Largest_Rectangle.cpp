class Solution {
private:
    vector<int> nextSmallerElement(vector<int> &arr, int n)
    {
        // Write your code here.
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> &arr, int n)
    {
        // Write your code here.
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n =heights.size();
        
        //for next smaller element of all heights
        vector<int> next;
        next = nextSmallerElement(heights,n);
        
        //for prev smaller element of all heights
        vector<int> prev;
        prev = prevSmallerElement(heights,n);
        
        int maxArea = INT_MIN;
        for(int i=0;i<n;i++){
            int l = heights[i];
            if(next[i] == -1){
                next[i] = n;
            }   
            int b = next[i] - prev[i] - 1;
            
            int area = l*b;
            maxArea = max(maxArea,area);
        }
        
        return maxArea;
    }
};
