#include<iostream>
using namespace std;
void checktriplets(int arr[],int n){//TC -> O(n^3) SC-> O(1)
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                count++;
            }
        }
    }
    cout<<"Number of triplets = "<<count;
}
int main(){
    int arr[]={10,20,30,40};
    checktriplets(arr,4);
}