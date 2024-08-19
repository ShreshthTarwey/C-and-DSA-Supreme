#include<iostream>
using namespace std;
void travsal(int arr[][2],int n,int m){
    cout<<"Row wise travsal"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // This method is only for column wise travesal
    //for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<arr[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<"General Method for column wise traversal"<<endl;
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int arr[3][2]={{10,20},
                {30,40},
                {50,60}};
    travsal(arr,3,2);

}