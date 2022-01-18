 vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<vector<string>> dp(n+1);
        dp[1].push_back("()");

        for(int i = 2; i <= n; i++) {
            set<string> cur;
            
            for(int j = 1; j < i; j++) {
            
                for(string s1: dp[j]) {
                    for(string s2: dp[i-j]) {
                        cur.insert(s1+s2);
                    }
                }
                
            }
            for(string s: dp[i-1]) {
                cur.insert("(" + s + ")");
            }
            dp[i] = vector<string>(cur.begin(), cur.end());
        }

        return dp[n];
    }

    /*
    parenthesis of len n can be generated either concatination of (parenthesis of len i + parenthesis of len (n-i)) or ( "(" + parenthesis of len n-1 + ")" )
 DP can be used to avoid overlapping sub-problems.
Time : O(N^2*S^2), Space: O(N*S), where S is no of valid parenthesis.
    
    */