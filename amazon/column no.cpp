string colName (long long int n)
    {
        // your code here
        long long int temp=n;
        string ans="";
        while(temp>0){
            temp--;
            int rem=temp%26;
            ans=string(1,'A'+rem)+ans;
            temp=temp/26;
            
        }
        //cout<<ans;
        return ans;

/*
temp-- is done to make it 0 based 
so that when it's 26 or 52 or so on we get remainder 0 but 'Z' is 25th position away from 'A'
so if we subtract initially then we avoid situation of zero remainder

*/