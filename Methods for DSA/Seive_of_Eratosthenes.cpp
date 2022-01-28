class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        
        //make bool vector
        vector<bool> prime(n+1,true);
        
        
        //start from 2 nos
        for(int i=2;i<n;i++){
            if(prime[i]==true){
                cnt++;
                
                //unmark the divisible of i
                for(int j=2*i; j<n; j=j+i){
                    prime[j]=0;
                }
            }
        }
        
        return cnt;
    }
};
