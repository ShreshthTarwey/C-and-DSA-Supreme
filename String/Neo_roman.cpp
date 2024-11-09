// You are using GCC
#include<iostream>
#include<string>
using namespace std;
class RomanNumeral{
    int num;
    string s1;
    public:
    int get(char c){
        if(c=='I') return 1;
        else if(c=='V') return 5;
        else if(c=='V') return 5; 
        else if(c=='X') return 10; 
        else if(c=='L') return 50;
        else if(c=='C') return 100; 
        else if(c=='D') return 500;
        else if(c=='M') return 1000; 
        
    }
    RomanNumeral(string s2) : num(0),s1(s2) {}
    operator int(){
        for(int i=0;i<s1.size();i++){
          if(i+1<s1.size() && get(s1[i])<get(s1[i+1])){
              num-=get(s1[i]);
          }
          else{
              num+=get(s1[i]);
          }
        }
        return num;
    }
};
int main(){
    string s;
    getline(cin,s);
    RomanNumeral obj(s);
    int n = obj;
    cout<<"Equivalent decimal number: "<<n;
}