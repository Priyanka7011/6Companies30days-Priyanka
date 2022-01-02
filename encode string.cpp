
string encode(string src)
{     
  //Your code here 
  int count=1;
  string ans="";
  for(int i=1;i<src.length();i++){
      if(src[i]==src[i-1]){
          count++;
      }
      else{
          ans+=src[i-1]+to_string(count);
          count=1;
          //cout<<src[i];
      }
      
  }
  ans+=src[src.length()-1]+to_string(count);
  //cout<<ans;
  
  return ans;
  
  //cout<<ans;
}     
 
//simply count the chracters. Didn't use map to reduce spae complexity. Time complexity=O(N) and space =o(1)