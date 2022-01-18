int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    int dp[n][n];
	    
	    for(int g=0;g<n;g++){
	        for(int i=0,j=g;j<n;j++,i++){
	            if(g==0){
	                dp[i][j]=A[i];
	            }
	            else if(g==1){
	                dp[i][j]=max(A[i],A[j]);
	            }else{
	                int val1 = A[i]+min(dp[i+2][j],dp[i+1][j-1]);
	                int val2 = A[j]+min(dp[i+1][j-1],dp[i][j-2]);
	                int val = max(val1,val2);
	                
	                dp[i][j]=val;
	            }
	        }
	    }
	    
	    return dp[0][n-1];
    }

    /*
    refer trello
    
    we only need upper diagonal dp 
    that's why we have used gap strategy to fill the table.
    gap strategy is filling the dp table diagonally.
     if g==0 that means when i and j are equal , which is the mail diagnal
     if g==1 means when i-j==1 , which is the second diagonal;
     hence we fill dp[0][n-1] in last which is our answer.s
    
    */