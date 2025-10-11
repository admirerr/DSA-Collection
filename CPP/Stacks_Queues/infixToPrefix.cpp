//infix to prefix
#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

int priority(char op) {
  if (op == '^') return 3;
  if (op == '*' || op == '/') return 2;
  if (op == '+' || op == '-') return 1;
  return 0;
}

string infixToPrefix(string &s){
  reverse(s.begin(), s.end()); //reversed a string
  int i=0;
  int n = s.size();
  while(i<n){//changing paranthesis
    if(s[i]=='('){
      s[i] = ')';
    } 
    else if(s[i]==')'){
      s[i] = '(';
    }
    i++;
  }

  i=0;
  string ans = "";
  stack<char> st;
  while(i<n){
    if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
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
      st.pop();
    }
    else{
      if(s[i] == '^'){
        while(!st.empty() && priority(s[i]) <= priority(st.top())){
          ans += st.top();
          st.pop();
        }
      }
      else{
        while(!st.empty() && priority(s[i]) < priority(st.top())){
          ans += st.top();
          st.pop();
        }
      }
      st.push(s[i]);
    }
    i++;
  }
  while(!st.empty()){
    ans += st.top();
    st.pop();
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  string s = "A+B*(C^D-E)^F+G*H-I";
  string ans = infixToPrefix(s);
  cout<<ans<<endl;
  return 0;
}

