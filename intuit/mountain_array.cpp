class Solution {
public:

    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int peak = 0;
        int end = (mountainArr.length())-1;
        int ele;
        
        while(peak!=end)
        {
            int mid = peak + (end-peak)/2;
            ele = mountainArr.get(mid);
            if(ele <mountainArr.get(mid+1))
                peak = mid+1;
            else if(ele >mountainArr.get(mid+1))
                end = mid;
        }
        
        
        int index = -1;
        int start = 0;
        end = peak;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            ele = mountainArr.get(mid);
            if(ele ==target)
            {
                index = mid;
                break;
            }
            else if(ele <target)
                start = mid+1;
            else
                end = mid-1;
        }
        if(index!=-1)
            return index;
        
            start = peak+1;
            end = mountainArr.length()-1;
            
            while(start<=end)
            {
                int mid = start + (end-start)/2;
                ele = mountainArr.get(mid);
                if(ele ==target)
            {
                index = mid;
                break;
            }
            else if(ele <target)
                end = mid-1;
            else
                start = mid+1;
            }
        
        
        return index;
        
    }
};
/*
first find the peak element in the array then apply 
binary search in the first half of the array which is 
in ascending order. If the element is not found then 
only apply binary search in the second half which is 
in decreasing order.

*/