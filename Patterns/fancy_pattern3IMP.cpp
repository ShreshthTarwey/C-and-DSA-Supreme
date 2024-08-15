#include <iostream>
using namespace std;
int fancy(int n)
{
    //Growing phase
    for(int i=0;i<n;i++){
        int cond = i<=n/2 ? 2*i:2*(n-i-1);
        for(int j=0;j<=cond;j++){
            if(j<=cond/2){
                cout<<j+1;
            }
            else{
                cout<<cond-j+1;
            }
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout << "Enter number of rows";
    cin >> n;
    fancy(n);
    return 0;
}