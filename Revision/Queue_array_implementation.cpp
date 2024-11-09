#include<iostream>
using namespace std;
int main(){
    char arr[100];
    int x;
    cin>>x;
    int i = -1;
    int j = -1;
    while(x!=4){
        switch (x)
        {
        case 1:
            /* code */
            if(i==-1 && j==-1){
                char c;
                cin>>c;
                j++;
                arr[++i] = c; 
            }
            else  if(i-j==4){
                cout<<"Queue is full."<<endl;
            }
            else{
                char c;
                cin>>c;
                arr[++i] = c;
                cout<<"The added element is: "<<c<<endl;
            }
            break;
        case 2:
            if(i==-1 && j==-1){
                cout<<"Queue is empty"<<endl;
            }
            else if(i==j){
                cout<<"Removed element is: "<<arr[j++]<<endl;
                i=j=-1;
            }
            else{
                cout<<"Removed element is: "<<arr[j++]<<endl;
            }
            break;
        case 3:{
            int k = j;
            if(i==-1 && j==-1){
                cout<<"Queue is empty."<<endl;
            }
            else{
                cout<<"The elements are: ";
                while(k<=i){
                    cout<<arr[k++]<<" ";
                }
            }
            break;
        }
        case 4:
            cout<<"Exitted the program"<<endl;
            return 0;
            break;
        
        default:
            cout<<"Invalid Entery"<<endl;
            break;
        }
    cin>>x;
    }
}