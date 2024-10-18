#include<iostream>
#include<vector>
using namespace std;

vector<int> spanfind(vector<int> arr) {
    vector<int> result;
    
    for(int i = 0; i < arr.size(); i++) {
        int count = 1;
        int j = i - 1;
        while (j >= 0 && arr[i] >= arr[j]) {
            count++;
            j--;
        }
        result.push_back(count);
    }
    
    return result;
}

int main() {
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = spanfind(arr);
    
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}
