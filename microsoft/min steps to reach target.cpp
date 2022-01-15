 int minSteps(int d){
        // code here
        int target=abs(d);
        int sum=0,step=1;
        while(sum<target || (sum-target)%2!=0){
            sum+=step;
            step++;
        }
        
        return step-1;
        //return 0;
    }


    /*
    target = 5. 
we keep on taking moves until we reach target or we just cross it. 
sum = 1 + 2 + 3 = 6 > 5, step = 3. 
Difference = 6 – 5 = 1. Since the difference is an odd value, we will not reach the target by flipping any 
move from +i to -i. So we increase our step. We need to increase step by 2 to get an even difference
 (since n is odd and target is also odd). Now that we have an even difference, we can simply switch 
 any move to the left (i.e. change + to -) as long as the summation of the changed
 value equals to half of the difference. We can switch 1 and 4 or 2 and 3 or 5. 
    
    */