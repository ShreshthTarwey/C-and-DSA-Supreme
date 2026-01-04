#include<bits/stdc++.h>

using namespace std;

void removeConsecutiveDuplicates(char *input) {
	if(input[0] == '\0' || input[1]=='\0'){
        return;
    }
	if(input[0] == input[1]){
        int i = 2;
        for(;input[i]!='\0';i++){
            input[i-1] = input[i]; 
        }
        input[i-1] = input[i];
        removeConsecutiveDuplicates(input);

    }
    // else
    removeConsecutiveDuplicates(input+1);
}
/*
Example:
xxab --> xab
*/
int main(){
    char  input[] = "xxab";
    removeConsecutiveDuplicates(input);

    cout<<input<<endl;
}