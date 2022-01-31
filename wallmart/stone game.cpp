bool stoneGame(vector<int>& arr) {
        
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int alice = 0;
        
        int bob = 0;
        
        int count = 0;
        
        while(arr.size() > 0)
        {
            if(count % 2 == 0)
            {
                alice += arr.back();
            }
            else
            {
                bob += arr.back();
            }
            
            count++;
            
            arr.pop_back();
        }
        
        return alice > bob;
    }
    /*
    simple observation approach
    we can also use DP as we have done in some other question(find it)
    
    */