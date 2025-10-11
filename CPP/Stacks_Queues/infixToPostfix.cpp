//infix to postfix conversion
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int priority(char op) {
  if (op == '^') return 3;
  if (op == '*' || op == '/') return 2;
  if (op == '+' || op == '-') return 1;
  return 0;
}

string infixToPostfix(string s){
  int n = s.size();
  int i=0;
  stack<char> st;
  string ans = "";
  while(i<n){
    if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
      ans = ans + s[i];
    }
    else if(s[i] == '('){
      st.push(s[i]);
    }
    else if(s[i] == ')'){
      while(!st.empty() && st.top() != '('){
        ans += st.top();
        st.pop();
      }
      st.pop(); // to pop opening bracket
    }
    else{//left only with operator
      while(!st.empty() && (priority(s[i]) < priority(st.top()) || (priority(s[i]) == priority(st.top()) && s[i]!= '^'))){
        ans += st.top();
        st.pop();
      }
      st.push(s[i]);
    }
    i++;
  }
  while(!st.empty()){
    ans += st.top();
    st.pop();
  }
  return ans;
}

int main(){
  string s = "A+B*(C^D-E)^F+G*H-I";
  string ans = infixToPostfix(s);
  cout<<ans;

  return 0;
}
