class Solution
{
  public:
  long long int power(long long int x,
                    long long int y,
                    long long int p)
{
    long long int res = 1ll;

    x = x % p;

    if (x == 0)
        return 0;

    while (y > 0) {

        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
    int kvowelwords(int N, int K) {
        // Write Your Code here
        long long int i, j;
    long long int MOD = 1000000007;

    // Array dp to store number of ways
    long long int dp[N + 1][K + 1] = { 0 };

    long long int sum = 1;
    for (i = 1; i <= N; i++) {

        // dp[i][0] = (dp[i-1][0]+dp[i-1][1]..dp[i-1][k])*21
        dp[i][0] = sum * 21;
        dp[i][0] %= MOD;

        // Now setting sum to be dp[i][0]
        sum = dp[i][0];

        for (j = 1; j <= K; j++) {
            // If j>i, no ways are possible to create
            // a string with length i and vowel j
            if (j > i)
                dp[i][j] = 0;
            else if (j == i) {
                // If j = i all the character should
                // be vowel
                dp[i][j] = power(5ll, i, MOD);
            }
            else {
                // dp[i][j] relation with dp[i-1][j-1]
                dp[i][j] = dp[i - 1][j - 1] * 5;
            }

            dp[i][j] %= MOD;

            // Adding dp[i][j] in the sum
            sum += dp[i][j];
            sum %= MOD;
        }
    }

    return sum;
    }
};


/*

Let dp[i][j] be the number of ways to make distinct strings of length i where the last j characters
 of the string are vowels.
So the states of dynamic programming are:
If j = 0, then dp[i][j] = (dp[i-1][0] + dp[i-1][1] +......+ dp[i-1][K])*21(represented by the integer variable sum) 
because the last added character should be a consonant then only the value of j will become 0 irrespective of its
 value on previous states.
If i<j then dp[i][j] = 0. Since it is not possible to create a string containing j vowels and has 
a length less than j.
If i == j, then dp[i][j] = 5 power i because the number of characters in the string is equal to the 
number of vowels, therefore all the characters should be vowels.
If j<i then dp[i][j] = dp[i-1][j-1]*5 because a string of length i with last j characters
 vowel can be made only if the last character is the vowel and the string of length i-1 has 
 last j - 1 character as vowels.
Print the sum of dp[n][0] + dp[n][1] + ...... + dp[n][K] as the answer.


*/