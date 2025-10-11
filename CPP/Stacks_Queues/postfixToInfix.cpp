//postfix to infix conversion 
#include<iostream>
#include<stack>
#include<string>
using namespace std;

string postfixToInfix(string s){
  int i=0;
  int n = s.size();
  stack<string> st;
  while(i<n){
    if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
      st.push(string(1,s[i]));
    }
    else{
      string tempB = st.top();
      st.pop();
      string tempA = st.top();
      st.pop();
      st.push("(" + tempA + s[i] + tempB +")");
    }
    i++;
  }
  return st.top();
}

int main(){
  string s = "AB-DE+F*/";
  string ans = postfixToInfix(s);
  cout<<ans<<endl;
  return 0;
}