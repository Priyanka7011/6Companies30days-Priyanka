int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum= accumulate(arr,arr+n,0LL);
	    bool dp[n+1][sum+1];
	    vector<int> v(sum/2);
	    int mn=INT_MAX;
	    
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=sum;j++){
	            if(i==0)
	              dp[i][j]=false;
	            if(j==0)
	               dp[i][j]=true;
	        }
	    }
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(arr[i-1]<=j)
	              dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            else
	               dp[i][j]=dp[i-1][j];
	        }
	    }
	    
	    for(int i=0;i<=sum/2;i++){
	        if(dp[n][i])
	           v.push_back(i);
	    }
	    
	    for(int i=0;i<v.size();i++){
	        mn=min(mn,sum-2*v[i]);
	    }
	    
	    
	    return mn;


	} 

    /*
    1. we need to understand that 
    diff = s2-s1;
    diff= (sum-s1)-s1
    diff= sum-2*s1;

    so only with the sum and sum of one of the set we can get the difference.

    2. the table represents possibilty of getting a sum with given no. of elements.
    so there is sum+1 columns and n+1 rows;
    so value in 2nd row 5th column means can we get sum 5 if we have only 2 elements in our set.

    0 1 2 3 4 5 6
  0 t f f f f f
  1 t
  2 t
  3 t

  3. first row of dp is all false because it means can we get a sum 1,2,3,4,5,6 etc. if we have zero 
  elements in set which is not possible that's why false
  first col is true because it means can we get sum 0 if we have 0,1,2,3 etc elements in our set.

  4. to fill the dp table ,
  we consider two cases : value i of array/set is considered or ignored.
  so if set is {1,2,3}
  to fill third row we check can we get sum 1,2,3,4,5,6 when we have 2 elements .
  for that we check if we already have sum j by taking only i-1 element
  or we have sum j-arr[i] by taking i-1 elements .

  5. to find the difference between sets we will consider values of last row only becuase in question we have n elements.
  we will take all those i values where entry in dp table is true which means we can get that sum.

  we are only traversing till half of the sum because above that diff will be negative 
  with same values as s1 sum will become greater than s2.
    
    
    */