#include <bits/stdc++.h>

using namespace std;

class Person{
    public:
    string name;
    int age;
    
    
    Person(string name , int age)
    {
        this->name=name;
        this->age=age;
    }
    
    // void getinfo()
    // {
    //     cout<<"Name:" <<name<<" age:"<<age <<endl;
    // }
    
   
    
};


class Student: public Person{
    public:
    int rollNo;

    // In Parametrized constructor in case of inheritance, u need to pass the parameters 
    //in the child class to the base class constructor also.
    Student(string name, int age, int rollno): Person(name,age)
    {
        this->rollNo=rollno;
    }

    void getInfo()
    {
       cout<<"name:" <<name<<" age:"<<age<<" rollNo:"<<rollNo<<endl; 
    }

};



int main() {
    Student s1("Pooja",18,88);

    s1.getInfo();
    
    
    cout<<endl;
}
