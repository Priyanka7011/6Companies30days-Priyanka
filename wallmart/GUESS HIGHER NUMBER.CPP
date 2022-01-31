int rec(int low , int high){
	if(low >= high) return 0;
	if(dp[low][high] != -1) return dp[low][high];

	int ans = INT_MAX;
	for(int i = low ; i <= high ; i++){
		//guessed i
		int case1 = i + rec(low , i - 1);//guessed i and it is higher than expected
		int case2 = i + rec(i + 1 , high);//guessed i and it is lower than expected
		ans = min(ans , max(case1, case2));
	}
	return dp[low][high] = ans;
}
/*
memoisation + recursion
to improve time complexity and to avoid solving overlapping set we are using dp table to store the values

*/