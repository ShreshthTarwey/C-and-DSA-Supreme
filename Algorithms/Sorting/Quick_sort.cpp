#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>&arr,int start,int end){
    int pos=start;
    for(int i=start;i<=end;i++)
    {
        if(arr[i]<=arr[end]){
            swap(arr[i],arr[pos++]);
        }
    }
    return pos-1;
}
void quickSort(vector<int>&arr,int start,int end){//Average Case(generally average case is asked for quickSort)->O(NlogN)
    if(start>=end){                               //Worse_Case(6,5,4,3,2,1)->O(N^2)  
        return;                                   //SC->O(n) for worse case  
    }                                             //SC->O(logn) for average casw                  
    int pivot = partition(arr,start,end);
    quickSort(arr,start,pivot-1);
    quickSort(arr,pivot+1,end);

}
int main(){
   vector<int> arr={6,5,4,3,2,1};
   quickSort(arr,0,5);
   for(auto i:arr){
    cout<<i<<" ";
   }
}