int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n);
        dp[0]=arr[0];
        
        dp[1]=arr[0]>arr[1]?arr[0]:arr[1];
        
        for(int i=2;i<n;i++){
            dp[i] = dp[i-2]+arr[i] > dp[i-1]? dp[i-2]+arr[i]: dp[i-1];
        }
        
        
        
        return dp[n-1];
    }