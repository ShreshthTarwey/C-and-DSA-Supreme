#include<iostream>
using namespace std;
bool binarySearch(int arr[],int n,int target)
{
    int left = 0;
    int right = n-1;
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(arr[mid]==target)
        {
            return true;
        }
        else if(arr[mid]>target)
        {
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return false;
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    cout<<binarySearch(arr,5,5);
}