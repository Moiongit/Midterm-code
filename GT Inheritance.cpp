#include <iostream>
using namespace std;

class Performer{
    private:
        string name;
        int age;
    
    public:
    Performer (string name, int age): name(name), age(age){}

        string getName(){
            return name;
        }

        int getAge(){
            return age;
        }

};

class Singer: public Performer{
    private:
        string vocalRange;
    
    public:
        Singer (string name, int age, string vocalRange): Performer (name, age), vocalRange(vocalRange){}

        string getVocalRange(){
            return vocalRange;
        }

        void sing() {
            cout << getName() << " is singing with a " << getVocalRange() << " range.";
        }
};

class Dancer: public Performer{
    private:
        string danceStyle;

    public:
        Dancer (string name, int age, string danceStyle): Performer (name, age), danceStyle(danceStyle){}
        
        string getDanceStyle(){
            return danceStyle;
        }

        void dance() {
            cout << getName() << " is performing " << getDanceStyle() << " dance.";
        }
};

int main() {

    int choice;

    cout << "What performer do you prefer? A singer(1) or a dancer(2)?: ";
    cin >> choice;

    switch (choice) {

        case 1: {
        string name;
        int age;
        string vocalRange;

        cout << "Enter a name: " << endl;
        cin >> name;

        cout << "Enter an age: " << endl;
        cin >> age;

        cout << "Enter a vocal range: " << endl;
        cin >> vocalRange;

        Singer singer(name, age, vocalRange);
        cout << "Singer's name is " << singer.getName() << "." << endl;
        cout << "Singer's age is " << singer.getAge() << "." << endl;
        cout << "Singer's vocal range is " << singer.getVocalRange() << "." << endl;
        singer.sing();
        break;

        }
        case 2: {
            string name;
            int age;
            string danceStyle;
    
            cout << "Enter a name: " << endl;
            cin >> name;
    
            cout << "Enter an age: " << endl;
            cin >> age;
    
            cout << "Enter a dance style: " << endl;
            cin >> danceStyle;
            
            Dancer dancer(name, age, danceStyle);
            cout << "Dancer's name is " << dancer.getName() << "." << endl;
            cout << "Dancer's age is " << dancer.getAge() << "." << endl;
            cout << "Dancer's dance style is " << dancer.getDanceStyle() << "." << endl;
            dancer.dance();
            break;
        }

        default:
        cout << "Invalid choice. Please enter from 1-2." << endl;

    }

    
    
    return 0;
}