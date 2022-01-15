vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int count=0;
        int n=arr.size();
        vector<vector<int>> ans;
        unordered_set<string> set;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l=j+1,r=n-1;
                while(l<r){
                    
                    if(arr[i]+arr[j]+arr[l]+arr[r]==k){
                        vector<int> temp;
                        
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[l]);
                        temp.push_back(arr[r]);
                        
                        //sort(temp.begin(),temp.end());
                        ans.push_back(temp);
                        //count++;
                        while(l<r && arr[l]==temp[2])
                           l++;
                        while(l<r && arr[r]==temp[3])
                          r--;
                    }
                    
                    else if(arr[i]+arr[j]+arr[l]+arr[r]<k){
                        l++;
                    }
                    else{
                        r--;
                    }
                    
                }
                while(j<n && arr[j]==arr[j+1]){
                    j++;
                }
            }
            while(i<n && arr[i]==arr[i+1]){
                i++;
            }
        }
        
        //cout<<count;
        
        return ans;
    }



    /*
    here we have to find unique quaduples that's why before incrementing i,j,l and r
    we checked if there's a same number after it and we skip those to make sure we get only unique quadruples.

    in such questions we use sliding window
    for the search of last set of number.
    in 2 sum problem it can be solved in O(n) because we can apply sliding window directly.

    in 3 sum problem it takes O(n2) because we first fix two values and then search for third
    value using sliding window

    in 3 sum problem it takes O(n3) because we first fix three values and then search for fourth
    value using sliding window
    
    l is the start of sliding window and r is the end.
    and we sort the array before applying the algo on array
    
    
    */