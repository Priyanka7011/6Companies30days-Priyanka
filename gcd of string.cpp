class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        string ans;
        //return (str1+str2==str2+str1 ? gcd(str1.length(),str2.length()):"");
        if(str1+str2==str2+str1){
            ans= str1.substr(0,gcd(str1.length(),str2.length()));
        }
        
        return ans;
        
    }
};