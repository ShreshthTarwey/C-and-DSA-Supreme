#include<iostream>
using namespace std;
void PrintallPairs(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i]<<","<<arr[j]<<"  ";
        }
        cout<<endl;
    }
}
void PrintUpward(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<arr[i]<<","<<arr[j]<<"  ";
        }
        cout<<endl;
    }
}
void PrintUpward1(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<arr[i]<<","<<arr[j]<<"  ";
        }
        cout<<endl;
    }
}
void PrintUpward2(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=i;j--){
            cout<<arr[i]<<","<<arr[j]<<"  ";
        }
        cout<<endl;
    }
}
void PrintUpward3(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            cout<<arr[i]<<","<<arr[j]<<"  ";
        }
        cout<<endl;
    }
}
void PrintUpward4(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<arr[i]<<","<<arr[j]<<"  ";
        }
        cout<<endl;
    }
}
int main(){
    int arr[]={10,20,30,40};
    // PrintallPairs(arr,4);
    // PrintUpward(arr,4);
    // PrintUpward1(arr,4);
    // PrintUpward2(arr,4);
    // PrintUpward3(arr,4);
    PrintUpward4(arr,4);

}