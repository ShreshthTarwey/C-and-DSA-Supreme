#include<iostream>
using namespace std;
void diamomd(int rows){
    for(int row=0;row<rows+1;row++){
        for(int space1=0;space1<rows-row;space1++){
            cout<<" ";
        }
        for(int star1=0;star1<row;star1++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int row=0;row<rows;row++){
        for(int space=0;space<row;space++){
            cout<<" ";
        }
        for(int star=0;star<rows-row;star++){
            cout<<"* ";
        }
        cout<<endl;
    }

}
int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    diamomd(n);
    return 0;
}