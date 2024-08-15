#include<iostream>
using namespace std;
void con_half(int rows){
    int i=1,j=1,count =1;
    while(i<=rows){
        j=1,count=i;
        while(j<=i){
            cout<<count;
            count++;
            j++;
        }
        i++;
        cout<<"\n";
    }
}
int main(){
    int n;
    cin>>n;
    con_half(n);
    return 0;
}