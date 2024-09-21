#include <iostream>
using namespace std;
class Animal {
public:
    virtual void makeSound() = 0;           // Pure virtual function
    void eat()
    {
    	cout<<"Animal is eating\n";
	}
};
class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Bark" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow" << endl;
    }
};
int main() {
    Dog d;
    Cat c;
    d.makeSound();
    d.eat();
    c.makeSound();
    c.eat();
    return 0;
}