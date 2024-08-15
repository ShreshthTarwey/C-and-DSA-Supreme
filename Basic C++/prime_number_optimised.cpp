#include<iostream>
using namespace std;
bool prime(int n){
    int factors = 0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;            
        }
    }
    return true;

}
int main(){
    int n;
    cin>>n;
    if(prime(n)){
        cout<<"Prime";
    }
    else{
        cout<<"Not a prime";
    }
}