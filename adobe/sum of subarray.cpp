vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int start=0,end=0;
        long long int sum=0;
        vector<int> ans;
        int flag=0;
        while(end<n){
            sum+=arr[end];
            while(sum>s){
                sum-=arr[start];
                start++;
                
            }
            if(sum==s){
                ans={start+1,end+1};
                flag=1;
                break;
                
            }
            
            end++;
        }
        if(!flag){
            ans={-1};
        }
        return ans;
    }