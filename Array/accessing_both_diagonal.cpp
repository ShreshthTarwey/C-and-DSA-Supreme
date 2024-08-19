#include<iostream>
using namespace std;
void diagonal(int arr[][3],int n,int m){
    //Brute force way
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(i==j){
    //         cout<<arr[i][j]<<" ";}
    //     }
    // }
    
    //Optimised way to do
    for(int i=0;i<n;i++){
        cout<<arr[i][i]<<endl;
    }
    cout<<"Diagonal number 2:-"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i+j==n-1){
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
    }

}
int main(){
    int arr[3][3]={{1,2,3},
                {4,5,6},
                {7,8,9}};
    diagonal(arr,3,3);
}