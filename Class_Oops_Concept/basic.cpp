#include<iostream>
#include<cstring>
using namespace std;
class Hero{
    public:
    int health;
    char level;
    public:
    char *name;
    //Setter and Getter you already know
    //Creating Constructors, Whenever you create a constructor the default constructor created by compiler dies
    Hero(){
        cout<<"Constructor is called"<<endl;
    }
    //Parametrised Constructor
    Hero(int health){
        cout<<"Parametrised is called"<<endl;
        //this represents the pointer that always refers to current obj that has been created 
        this->health=health;
        // (*this).health=health; same thing

    }
    Hero(int health, char level, char name[]){
        this->level = level;
        this->health = health;
        this->name = new char[100];
        this->name = name;
    }

    //Creating Deep Copy constructor


    Hero(Hero &temp){
        this->level  = temp.level;
        this->health = temp.health;
        //now creating deep copy
        char *ch  = new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name = ch;
        //We have created new char array and then copied so untill ch is not changed no change will happen in name of created obj.
    }
    void setName(char name[]){
        strcpy(this->name,name);
    }
    void print(){
        cout<<"Name: "<<this->name<<endl;
        cout<<"Level: "<<this->level<<endl;
        cout<<"Health: "<<this->health<<endl;
    }
    //Our Own Copy constructor, once we create it the default created copy constructor dies
    // Hero(Hero &temp){
    //     this->health = temp.health;
    // }


    //Creation of destructor
    ~Hero(){
        cout<<"Destructor is called"<<endl;
    }
};
int main(){

    //Creating Destructor
    //Static  Allocation
    Hero hero1;

    //Dynamic Allocation
    Hero *hero2 = new Hero();

    // You will notice that constructor is called twice, but destructor is called only once, cause destructor is called for static created memory automatically but not for dynamically created obj.
    delete hero2;




    // //Our created copy constructor removed, so default can work
    // char name[9]="Shreshth";
    // Hero hero1(10,'D',name);
    // hero1.print();
    // //Now using default copy constructor
    // Hero hero2(hero1);
    // //Or
    // //Hero  hero2 = hero1;
    // hero2.print();
    

    // //Now Concept of shallow copy  starts
    // hero1.name[0]='G';
    // hero1.print();
    // hero2.print();
    // //You will observe both the names in both object is changed
    // //Because shallow copy is happening by default
    
    // //Now we are using cop  assingment operator 

    // //"Which is '=' in this case"
    // hero2 = hero1;
    // hero1.print();
    // hero2.print();



    // //Now creating deep copy

    




    // // //Copy Constructor
    // // Hero suresh(10);
    // // Hero ramesh();
    // // // ramesh.health = suresh.health;
    // // // Above statement is replaced by below statement
    // // Hero ramesh(suresh); //Here default copy constructor is called , we can create our own copy constructor





    // // //Static Allocation of obj
    // // Hero obj2;
    // // //dynamic allocation of an obj
    // // Hero *obj = new Hero(10);
}