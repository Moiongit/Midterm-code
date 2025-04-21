#include<iostream>
using namespace std;

class Person {
    private:
        string name;
        int age;

    public:
        Person(string name, int age):name(name), age(age){}

    string getName(){
        return name;
    }

    int getAge(){
        return age;
    }
};

class Student: public Person{
    private:
        string studentId;

    public:
    Student(string name, int age, string studentId): Person(name, age), studentId(studentId){} 

    string getStudentId() {
        return studentId;
    }

    void display() {
        cout << getStudentId() << "is John student ID.";
    }
};

class Worker: public Person{
    private:
        string workType;

    public:
        Worker(string name, int age, string workType): Person(name, age), workType(workType){}

    string getWorkType() {
        return workType;
    }
};

int main(){
    Student s1("John", 20, "273839");
    cout << "Student name: " << s1.getName() << endl;
    cout << "Student age: " << s1.getAge() << endl;
    s1.display();

    Worker w1("Moi", 19, "Project Manager");
    cout << "Worker name: " << w1.getName() << endl;
    cout << "Worker name: " << w1.getAge() << endl;
    cout << "Worker role: " << w1.getWorkType() << endl;

    return 0;
}