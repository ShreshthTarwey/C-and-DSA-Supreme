#include<iostream>
#include<math.h>
using namespace std;
void toh(int n,int src,int help,int desc){//TC-> 2^n-1 which means O(2^n) SC-> O(n)

    if(n==1){
        cout<<"Moved disc "<<n<<" from "<<src<<" to "<<desc<<endl;
        return;
    }


    toh(n-1,src,desc,help);
    cout<<"Moved disc "<<n<<" from "<<src<<" to "<<desc<<endl;
    toh(n-1,help,src,desc);
}
int main(){
    int n=10;
    toh(n,1,2,3);
    cout<<"Total moves was: "<<pow(2,n)-1<<endl;
}