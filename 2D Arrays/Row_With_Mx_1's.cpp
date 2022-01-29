int rowMaxOnes(vector<vector<int>>& arr, int n, int m) {
    // Write your code here.
        int maxCnt = -1;
	    int ans = -1;
	    
	    for(int i=0;i<n;i++){
	        
	        int cnt = 0;
	        for(int j=0;j<m;j++){
	            if(arr[i][j] == 1){
	                cnt++;
	            }
	        }
	        
	        if(cnt>maxCnt){
	            maxCnt = cnt;
	            ans = i;
	        }
	    }
	    
	    return ans;
}

