#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Function to convert postfix expression to prefix
string postfixToPrefix(string s){
    int n = s.size();          // length of the postfix expression
    stack<string> st;          // stack to store intermediate strings

    int i = 0;                 
    while(i < n){
        // If current character is an operand (letter or digit)
        if((s[i]>='a' && s[i]<='z') || 
           (s[i]>='A' && s[i]<='Z') || 
           (s[i]>='0' && s[i]<='9')){
            // Push operand as a string onto the stack
            st.push(string(1, s[i]));
        }
        else{
            // If current character is an operator
            // Pop top two operands from stack
            string right = st.top(); st.pop();  // right operand
            string left = st.top(); st.pop();  // left operand

            // Concatenate operator + left operand + right operand
            // and push back to stack
            st.push(string(1, s[i]) + left + right);
        }
        i++;
    }

    // Final element of stack is the prefix expression
    return st.top();
}

int main(){
    string s = "AB-DE+F*/";          // example postfix expression
    string ans = postfixToPrefix(s); // convert to prefix
    cout << ans << endl;             // output prefix expression
    return 0;
}
