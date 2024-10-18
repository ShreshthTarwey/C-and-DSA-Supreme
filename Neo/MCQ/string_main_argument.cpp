#include<iostream>
#include<string>
using namespace std;
int main(int argc,char* argv[]){//argc tells you how many arguments were passed (including the program name).
// argv is an array of C-strings (null-terminated character arrays) that hold the actual argument values.
// This is useful when building command-line tools or programs that require external input through arguments.
string str;
cin>>str;
str+="Modified";
cout<<str<<endl;
//What is the output if input is Hello World?
}