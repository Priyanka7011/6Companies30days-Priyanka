int lengthOfLongestAP(int arr[], int n) {
        // code here
        if(n<=2) return n;
        
        int maxlength=2;
        int dp[n][n];
        for(int i=0;i<n;i++){
            dp[i][n-1]=2;
        }
        
        for(int j=n-2;j>=1;j--){
            int i=j-1 ,k=j+1;
            while(i>=0 && k<=n-1){
                if(arr[i]+arr[k]<2*arr[j])
                k++;
                else if(arr[i]+arr[k]>2*arr[j]){
                    dp[i][j]=2;
                    i--;
                }else{
                    dp[i][j]=dp[j][k]+1;
                    maxlength=max(maxlength,dp[i][j]);
                    i--;k++;
                }
                
                
                
            }
            while(i>=0){
                dp[i][j]=2;
                i--;
            }
        }
        
        return maxlength;
        
    }


    /*
    here in this question we are filling dp table from the last column

    the i,j in dp table represents the length of ap if i and j are the two elements of ap.

    so if {1,4,5,7,9,10} is array

    **note : any two elements are always in ap.

    it's definite that if last elements and any other element are in ap then there won't be any third element
    to continue the ap thus the length is 2 if the second element of ap is the last element of the array.

    so prefill the last column with 2.

    now start filling from last column.
    choose three values i,j and k .
    we know that in ap i+k = 2*j

    example

           i j k
    {1,4,5,7,9,10}
     0  1 2 3 4 5

    7+10 != 2*9
    and 17 < 18 so we should increase k because then only we can get greater sum 
    and when we do k++ array ends

    so now we update j value by j--

         i j k 
    {1,4,5,7,9,10}
     0  1 2 3 4 5
    
    5+9 = 2*7
    it's equal so remember we will update value of dp[i][j]
    as i<j<k dp[j][k] will be already filled as we are moving from right to left
    thus
    dp[i][j]=dp[j][k]+1;  //+1 because if j and k was part of AP then they have one more member at i t
                          which can be part of the ap so length is increase by 1.
    
    that's why we are updating dp value only when we are decrementing i
    to ensure till that i,j we know the lengths of possible ap after that it's nect ap.

    also in case when k goes out of bound but i>=0
    then it means for all the left dp[i][j] value length will be 2.

           i j  k
    {1,4,5,7,9,10}
     0  1 2 3 4 5

    so here k is exceeded but i didn't 
    it means if we have 7 and 9 in AP we won't get the third member as k exceeds 
    but i is still greater than 0;
    so it's very clear that if we aren't getting third member for 7 and 9 in AP
    we won't get third member for 5 and 9 , 4 and 9 and so on
    as d increases but we don't have values in array
    thus we can simply put 2 in dp table 


    



    

    

    
    
    */