// Ronald Woods
// CIS310 - Week __
// Simple classes with intentional errors

#include <iostream>
using namespace std;

class Dog {
public:
    string name;
    int age;
};

class Cat {
public:
    string name;
    int age;
};

int main() {

    Dog myDog;
    myDog.name = "Buddy";
    myDog.age = 3;

    Cat myCat;
// Corrected Age to age as the complier is case sensitive
    myCat.age = 5;
// Added se4micolon to terminate the statement
    cout << "My dog is " << myDog.age << " years old";

        return 0;
}