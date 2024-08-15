#include<iostream>
using namespace std;
int main(){
    char k;
    cout << "Enter your character: " << endl;
    cin >> k;
    switch(k){
        case 'A':
        cout << "Very good grade";
        break;
        case 'B':
        cout << "Very Bad grade";
        break;
        default:
        cout << "Oops";
    }
}