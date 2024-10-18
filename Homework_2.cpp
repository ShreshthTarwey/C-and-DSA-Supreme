#include<iostream>
#include<string>
#include<stack>
using namespace std;

int bracket(string s){
    stack<char> stk;
    
    if(s.size()&2!=0){
        return -1;
    }
    else{
        for(int i=0;i<s.size();i++){
            char c = s[i];
        if(stk.empty()){
            if(c=='(' || c==')')
            stk.push(c);
        }
        else if(stk.top()=='(' && c==')'){
            stk.pop();
        }
        else if(stk.top()==')' && c=='('){
            stk.pop();
        }
        else{
            if(c=='(' || c==')')
            stk.push(c);
        }
     }
    }
    return stk.empty();
}
int main(){
    string s;
    getline(cin,s);
    // cout<<bracket(s)<<endl;
    if(bracket(s)){
        cout<<"String is balanced";
    }
    else{
        cout<<"String is not balanced";
    }
}