class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int ans = 0;
        int i = 1 , n = arr.size() , inc_start , inc_end , dec_start ,dec_end ;
        
        while(i < n){
            
			
			// Considering the increasing sequence
            inc_start = i-1;
            while(i < n && arr[i] > arr[i-1]) i++;
            inc_end = i-1;
            
			// Checking if there is a sequence containing equal numbers
            while(i < n && arr[i] == arr[i-1]) i++;
            
			
			// Considering the decreasing sequence
            dec_start = i-1;
            while(i<n && arr[i-1] > arr[i]) i++;
            dec_end = i-1;
            
			
			// Checking if there are elements in the increasing and decreasing sequence and both increasing and decreasing sequences lie next to each other
            if(inc_end != inc_start && dec_end!= dec_start && inc_end == dec_start) ans = max(ans , dec_end - inc_start+1);
            
        }
        
        return ans;
        
    }
};

/*
time complexity is O(n) becuase we are not traversing through those values which are already traversed
It takes only one pass
*/