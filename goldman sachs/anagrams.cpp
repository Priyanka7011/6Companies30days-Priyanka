vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        unordered_map<string,vector<string>> hash;
        vector<vector<string>> ans;
        
        for(auto s:string_list){
            string temp=s;
            sort(s.begin(),s.end());
            hash[s].push_back(temp);
            
        }
        
        for(auto m:hash){
            vector<string> test;
            for(auto x :m.second){
                //cout<<x<<" ";
                test.push_back(x);
            }
            //cout<<"\n";
            ans.push_back(test);
            test.clear();
        }
        
        return ans;
        
    }