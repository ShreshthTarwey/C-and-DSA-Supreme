#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<"*";
    //     }
    
    // //For spaces
    //     for(int j=0;j<=n-i-1;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<=n-i-1;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<=i;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // //Lower half
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=n-i-1;j++){
    //         cout<<"*";
    //     }
    //     for(int j=0;j<=i;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<=i;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<=n-i-1;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    //Upper half
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        for(int j=0;j<(2*n)-2-(2*i);j++){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    //lower half
    for(int i=0;i<n;i++){
        for(int j=0;j<=n-i-1;j++){
            cout<<"*";
        }
        for(int j=0;j<2*i;j++){
            cout<<" ";
        }
        for(int j=0;j<=n-i-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    
}