int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
        }
        
        if(sum&1)
           return 0;
        
        int dp[n+1][(sum/2)+1];
        for(int i=0;i<=n;i++){
	        for(int j=0;j<=sum/2;j++){
	            if(i==0)
	              dp[i][j]=0;
	            if(j==0)
	               dp[i][j]=1;
	        }
	    }
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum/2;j++){
	            if(arr[i-1]<=j){
	                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
	            }
	            else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    
	    
	    return dp[n][sum/2];
	    
    }

    /*
    this is similar to microsoft's minimum subset difference
    if sum is odd there's no way to divide array into two subset of equal sum
    the differences are:
    we are only considering columns till sum/2 as if we get sum of values of array as sum/2
    it's definite that the sum of rest of the values are sum/2

    so if dp[n][sum/2] is true we can say that it's possible to get two subset pf equal sum
    
    */