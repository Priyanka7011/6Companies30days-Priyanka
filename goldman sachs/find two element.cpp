class Solution{
  public:
    int *findTwoElement(int *arr, int n) {
        // code here
        vector<int> v(n+1,0);
        int* ans=(int*)malloc(2*sizeof(int));
        for(int i=0;i<n;i++){
            v[arr[i]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(v[i]==2){
                ans[0]=i;
            }
            if(v[i]==0){
                ans[1]=i;
            }
        }
        
        return ans;
    }
       
};

