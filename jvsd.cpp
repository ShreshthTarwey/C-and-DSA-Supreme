// You are using GCC
#include <stdio.h>

void merge(float arr[], int left, int mid, int right) {
    //Type your code here
    int cap = right-left+1;
    float temp[cap];
    int l = left, r = mid+1, index = 0;
    while(l<=mid && r<=right){
        if(arr[l]<arr[r]){
            temp[index++] = arr[l++];
        }
        else{
            temp[index++] = arr[r++];
        }
    }
    index=0;
    while(l<=mid){
        temp[index++] = arr[l++];
    }
    while(r<=right){
        temp[index++] = arr[r++];
    }
    while(left<=right){
        arr[left++] = temp[index++];
    }
}

void mergeSort(float arr[], int left, int right) {
    //Type your code here
    if(left==right){
        return;
    }
    int mid = left + (right-left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}