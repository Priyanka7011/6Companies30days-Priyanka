   bool canPair(vector<int> nums, int k) {
        // Code here.
        vector<int> arr(k,0);
        for(int i=0;i<nums.size();i++){
            arr[nums[i]%k]++;
        }
        if(nums.size()%2!=0){
            return false;
        }
        int half=k/2;
        //cout<<half;
        //bool flag=true;
        int pairs=0;
        for(int i=0;i<=half;i++){
            if(i==0 or (i==half && k%2==0)){
                pairs+=(arr[i])/2;
            }else{
                int val=arr[i]<arr[k-i]?arr[i]:arr[k-i];
                //cout<<val;
                pairs+=val;
            }
            
        }
        //cout<<pairs;
        if(pairs==nums.size()/2){
            return true;
        }
        
        return false;
        
    }

    /*
    we only have to count pairs and one number can be paired with only one k-i number.
    we do not have to consider all possible pairs (e.g 1 3 1 3 then ans= 2 pairs not 4 pairs )
    */