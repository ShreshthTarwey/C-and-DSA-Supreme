#include<iostream>
#include<vector>
#include<string>
using namespace std;
 


bool anagram(string s1,string s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    for(int i=0;i<s1.length();i++){
            int flag = 0;
            for(int j=0;j<s2.length();j++){
                if(s1[i]==s2[j]){
                    flag = 1;
                }
            }
            if(!flag){
                return false;
            }
        }
        return true;
}
int main(){
    string s1;
    string s2;
    cin>>s1>>s2;
    cout<<anagram(s1,s2);
}