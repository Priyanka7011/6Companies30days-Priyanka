long long countWays(int m)
    {
        // your code here
        long long dp[m+1];
        dp[0]=1,dp[1]=1;
        for(int i=2;i<=m;i++){
            dp[i]=dp[i-2]+1;
        }
        return dp[m];
    }

/*
till i-2 step all those ways in which we have to take two step size tp reach i'th position
are considered.
And 1 more way left is to take one step size to reach ith position .
here order of step doesn't matter (1,2,2 or 2,2,1 both are same)

*/