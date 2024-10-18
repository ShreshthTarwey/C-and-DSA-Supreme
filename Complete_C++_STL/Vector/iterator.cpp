#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr(5,0);
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(120);
    arr.push_back(102);
    arr.push_back(1022);

    vector<int>::iterator it = arr.begin();
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"-----------------------------------------------"<<endl;
    while(it!=arr.end()){
        cout<<*it<<" ";
        it++;
    }
}