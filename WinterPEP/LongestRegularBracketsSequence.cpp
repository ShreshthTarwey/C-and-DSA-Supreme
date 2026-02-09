#include<bits/stdc++.h>

using namespace std;
// )((())))(()())


int main(){
    string s;
    cin>>s;
    stack<int>st;
    st.push(-1);
    int len  = 0;
    int count = 0;
    for(int i=0;i<s.length();i++){
        if(st.top()!=-1 && s[st.top()] == '(' && s[i] == ')'){
            st.pop();
            if(len<(i-st.top())){
                count = 1;
                len = i-st.top();
            }
            else if(len == (i-st.top())){
                count++;
            }
            else{
                continue;
            }
        }else{
            st.push(i);
        }
    }
    if(len == 0) count = 1;
    cout<<len<<" "<<count;
}