string FirstNonRepeating(string A){
		    // Code here
		    int hash[26]={0};
		    string ans="";
		    
		    deque<int> dq;
		    
		    for(auto it:A){
		        int pos=it-'a';
		        
		        if(hash[pos]==0){
		            dq.push_back(it);
		        }
		        hash[pos]++;
		        
		        while(!dq.empty() && hash[dq.front()-'a']!=1)
		        dq.pop_front();
		        
		        if(dq.empty()) ans+="#";
		        else
		        ans+=dq.front();
		    }
		    
		    return ans;
		}
/*
whenever we have to deal with subarrays or substring use deque such that keep the answer
in the front of the queue and push successive values from back
*/