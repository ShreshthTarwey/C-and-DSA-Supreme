#include<iostream>
using namespace std;
void print_p(int n)
{
    int num=1;
    for(int i=0;i<n;i++)
    {
        //Spaces
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        for(int k=0;k<=i;k++)
        {
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    print_p(n1);
    print_p(n2);
    print_p(n3);
}