 vector<string> winner(string arr[],int n)
    {
        
        vector<string> ans{"0","0"};
        map<string,int> m;
        
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        int max=0;
        for(auto i:m){
            if(max<i.second){
                max=i.second;
                ans[0]=i.first;
                ans[1]=to_string(max);
            }
        }
        
        return ans;
        
    }