#include<iostream>
using namespace std;
void waterJugProblem(int capacity1,int capacity2,int goal)
{
    int jug1 = 0,jug2 = 0;
    while(jug1!=goal && jug2!=goal)
    {
        if(jug1==0)
        {
            jug1 = capacity1;
            cout<<"Fill Jug1: Jug1 = "<<jug1<<" Jug2 = "<<jug2<<endl;
        }
        else if(jug2<capacity2)
        {
            int pour = min(jug1,capacity2-jug2);
            jug1 -= pour;
            jug2 +=pour;
            cout<<"Pour from Jug1 to Jug2 = "<<jug1<<" Jug2 = "<<jug2<<endl;
        }
        else if(jug2==capacity2){
            jug2 = 0;
            cout<<"Empty Jug2: Jug1 = "<<jug1<<" Jug2 = "<<jug2 <<endl;
        }
    }
    cout<<"Jug1 = "<<jug1<<" Jug2 ="<<jug2<<endl;
}
int main()
{
    int capacity = 5, capacity2 = 4, goal  = 3;
    waterJugProblem(capacity,capacity2,goal);
    return 0;
}
