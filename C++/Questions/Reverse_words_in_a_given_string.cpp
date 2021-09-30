//Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  string reverseWords(string S) {
    vector<string> temp;
    string str="";

    for(char ch:S){
      if(ch=='.'){
        temp.push_back(str);
        str="";
      } else { 
        str += ch;
      }
    } 
    
    temp.push_back(str); 
    str=""; 

    for(int i = temp.size()-1;i>0;i--){ 
      str+= temp[i]; 
      str.push_back('.'); 
    } 
    
    str+=temp[0]; 
    return str;  
  } 
};

int main() 
{ 
  int t; 
  cin >> t; 
  while (t--) 
  { 
    string s; 
    cin >> s; 
    Solution obj; 
    cout<<obj.reverseWords(s)<<endl; 
  }
}