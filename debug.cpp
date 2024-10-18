#include<iostream>
using namespace std;

// int main(){
//     int n, sum=0;// Not able to see that sum was not initialised to 0
//     cin >> n;
//     int input[n];
//     for(int i=0;i<n;i++){
//         cin >> input[i];
//     }
//      for(int i=0; i<n; i++){
//          sum = sum + input[i];
//      }
//     cout << sum << endl;
//     return 0;
// }
int linearSearch(int arr[], int n ,int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            return 1;
        }
    }
    return 0;
}
void populate(int arr[],int n){
    int j=0;
    for(int i=0; i < n; i = i + 2){
        arr[n-j-1] = i+2;
        arr[j] = i+1;
        j++;
    }
}
// void swapAlternate(int arr[],int size){
//     for(int i=0;i<size-1;i=i+2){
//         int temp = arr[i+1];
//         arr[i+1] = arr[i];
//         arr[i] = temp;
//     }
// }

int pairSumToX(int input[], int size, int x){
	int pairs = 0;
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(input[i] + input[j] == x) pairs++;
		}
	}
	return pairs;
}
void swapAlternate(int arr[],int size){

    for(int i=0;i<size-1;i=i+2){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
}
int tripletSumToX(int input[], int size, int x){
	int triplets = 0;
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			for(int k=j+1; k<size; k++){
				if(input[i] + input[j] + input[k] == x) triplets++;
			}
		}
	}
	return triplets;
}
void sort0sand1s(int input[], int size){
	int nextZero = 0;
	for(int i=0; i<size; i++){
		if(input[i] == 0){
			int temp = input[nextZero];
			input[nextZero] = input[i];
			input[i] = temp;
            nextZero++;
		}
	}
}
int main(){
    int n;
    int arr[]={1,2,3,4,5,6};
    // if(linearSearch(arr,5,4)){
    //     cout<<"Target exist ";
    // }
    // else{
    //     cout<<"Target do not exist";
    // }
    // populate(arr,6);
    // swapAlternate(arr,6);

    // for(int i=0;i<6;i++){
    //     cout<<arr[i]<<" ";
    // }
    int arr2[]={0,1,0,1,1,1,0};
    sort0sand1s(arr,7);
    for(int i=0;i<7;i++){
        cout<<arr2[i]<<" ";
    }
    // cout<<pairSumToX(arr,6,6);
}