#include<iostream>
#include<string>
using namespace std;
int lcs(string &s1, string &s2,int i,int j) {
    if (i == 0 || j == 0)
        return 0;
    if (s1[i] == s2[j]){
        return 1 + lcs(s1, s2, i+1, j+1);}
    else{
        return max(lcs(s1, s2, i, j+1), max(lcs(s1, s2, i+1, j),lcs(s1,s2,i+1,j+1)));}
}
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    
}