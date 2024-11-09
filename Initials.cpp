#include<bits/stdc++.h>
using namespace std;

// .dat -> stores the information!
int main(){
//cin ,cout
// stringstream
fstream fs("student.dat", ios::out | ios::binary);
if(!fs){
cout<<"file cannot be generated!"<<endl;
fs.close();
return 1;
}
string s ="jitesh";
fs.write(s.c_str(), s.size());

return 0;
}