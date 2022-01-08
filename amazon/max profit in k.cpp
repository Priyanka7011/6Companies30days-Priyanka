public:
    int maxProfit(int k, int n, int arr[]) {
        // code here
        int dp[k+1][n];
        memset(dp,0,sizeof(dp));
        for(int t=1;t<=k;t++){
            int max=INT_MIN;
            for(int d=1;d<n;d++){
                if(dp[t-1][d-1]-arr[d-1]> max){
                    max = dp[t-1][d-1]-arr[d-1];
                }
                if(max+arr[d] > dp[t][d-1]){
                    dp[t][d]= max+arr[d];
                }else{
                    dp[t][d]=dp[t][d-1];
                }
            }
        }
        
        return dp[k][n-1];
    }

    /*

    explanation in trello
    */