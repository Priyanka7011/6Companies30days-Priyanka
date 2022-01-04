class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
        long long int end=0,start=0,p=1,count=0;
        
        while(end<n){
            p*=a[end];
            while(start<n && p>=k){
                p=p/a[start];
                start++;
            }
            if(p<k){
                count+=end-start+1;
            }
            
            end++;
        }
        
        return count;
    }
};


//this approach is called sliding window
// as the array can be in any order so that's why we have the second while loop
//where we change the start index so we can consider middle subarrays as well.