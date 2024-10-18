#include<iostream>
#include<vector>
using namespace std;
vector<int> spanfind(vector<int>arr){
    vector<int>result;
    int count = 0;
    int index = 0;
    for(int i=0;i<arr.size();i++){
        count=1;
        int j=i;
        while(j>=0){
            
            if(j-1>=0 && arr[i]>=arr[j-1]){
                count++;
            }
            else{
                break;
            }
            j--;
        }
        result.push_back(count); 
    }
    return result;
}
int main(){
    vector<int> arr = {100,80,60,70,60,75,85};
    vector<int>result = spanfind(arr);
    for(int i=0;i<arr.size();i++){
        cout<<result[i]<<" ";
    }
}