public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    int dp[n+1][sum+1];
	    
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=sum;j++){
	            if(i==0){
	                dp[i][j]=0;
	            }
	            if(j==0){
	                dp[i][j]=1;
	            }
	        }
	    }
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(arr[i-1]<=j){
	                dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            }else{
	                dp[i][j]= dp[i-1][j];
	            }
	        }
	    }
	    
	    vector<int> v;
	    for(int i=0;i<=sum/2;i++){
	        if(dp[n][i]==1){
	            v.push_back(i);
	        }
	    }
	    
	    int mn=INT_MAX;
	    for(int i=0;i<v.size();i++){
	        if(sum-(2*v[i])<mn){
	            mn=sum-2*v[i];
	        }
	    }
	    
	    return mn;
	    
	    
	} 