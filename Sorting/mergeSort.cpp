void merge(vector < int > & arr, int s, int e){
    int mid = (s+e)/2;
    int n1 = mid - s + 1;
    int n2 = e-mid;
    
    int a[n1];
    int b[n2];
    //copy values in both new arrays
    int k=s;
    for(int i=0;i<n1;i++){
        a[i]=arr[k];
        k++;
    }
    k = mid+1;
    for(int i=0;i<n2;i++){
        b[i]=arr[k];
        k++;
    }
    
    int i=0;
    int j=0;
    k=s;
    //merging 2 arrays
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++;
        j++;
    }
}

void solve(vector < int > & arr, int s, int e){
    
    if(s>=e){
        return;
    }
    
    int mid = (s+e)/2;
    //for left array
    solve(arr,s,mid);
    //for right array
    solve(arr,mid+1,e);
    
    //merging both the arrays
    merge(arr,s,e);
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    solve(arr,0,n-1);
}
