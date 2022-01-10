class Solution {
  public:
    long long squaresInChessBoard(long long n) {
        // code here
        long long int ans=((n)*(n+1)*(2*n+1))/6;
        return ans;
    }
};

/*
if n=8
ans= 1^2 + 2^2 + 3^2 + 4^2 +............+n^2
sum of sqaures of n numbers
*/