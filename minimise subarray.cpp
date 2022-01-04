class Solution{
  public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int start=0,end=0;
        int sum=0;
        vector<int> length;
        while(end<nums.size()){
            sum+=nums[end];
            while(sum>=target){
                length.push_back(end-start+1);
                sum-=nums[start];
                start++;
            }
            
            end++;
        }
        if(length.size()==0)
            return 0;
        
        int min=100001;
        for(auto a:length){
            if(min>a)
                min=a;
        }
        
        return min;
    }
       
       
};

/*

sliding method is used
*/