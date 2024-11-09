#include<iostream>
using namespace std;
void TOH(int n,int src,int help,int desc){
    if(n==1){
        cout<<"Moved disk "<<n<<" from "<<src<<" to "<<desc<<endl;
        return;
    }
    TOH(n-1,src,desc,help);
    cout<<"Moved disk "<<n<<" from "<<src<<" to "<<desc<<endl;
    TOH(n-1,help,src,desc);
}

int main(){
    int n = 3;
    TOH(3,1,2,3);
}