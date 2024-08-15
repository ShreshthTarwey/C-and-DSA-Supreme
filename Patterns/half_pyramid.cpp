#include<iostream>
void pyramid(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
}
int main(){
    int n;
    std::cout<<"Enter number of rows: "<<std::endl;
    std::cin>>n;
    pyramid(n);
    return 0;
}