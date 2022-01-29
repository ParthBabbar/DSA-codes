class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        
        vector<int> arr;
        
        //print every element of matrix in array
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int element = Mat[i][j];
                arr.push_back(element);
            }
        }
        
        //sort the array
        sort(arr.begin(),arr.end());
        
        int k=0;

        //print the sorted array in matrix
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                Mat[i][j]=arr[k];
                k++;
            }
        }
        
        return Mat;
    }
};
