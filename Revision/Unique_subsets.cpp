#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"{}"<<endl;
    for(int i=0;i<n;i++){
        cout<<"{ "<<arr[i]<<" }"<<endl;

        for(int j=i+1;j<n-1;j++){
            if(j==i){
                continue;
            }
            else{
                cout<<"{ "<<arr[i]<<","<<arr[j]<<" }"<<endl;
            }
        }
    }
    cout<<"{";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<", ";
    }
    cout<<"}";
}