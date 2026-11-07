#include <iostream>
using namespace std;

class Animal {
public:
    Animal() { cout << "Animal constructed\n"; }
    virtual void speak() const { cout << "Animal sound\n"; }
    virtual ~Animal() { cout << "Animal destroyed\n"; }
    //~Animal() { cout << "Animal destroyed\n"; }
};

//
class Dog : public Animal {
public:
    Dog() { cout << "Dog constructed\n"; }
    void speak() const override { cout << "Woof\n"; }
    //~Dog() override { cout << "Dog destroyed\n"; }
    ~Dog() { cout << "Dog destroyed\n"; }
};
//

/*
class Dog : public Animal {
private:
    int* readings;  // Dog owns this dynamic array.
public:
    Dog() : readings(new int[3] {0, 0, 0}) { cout << "Dog constructed\n"; }
    void speak() const override { cout << "Woof\n"; }
    //~Dog() override {
	~Dog() {
        delete[] readings;  // Match new[] with delete[].
        cout << "Dog readings released\n";
    }
    Dog(const Dog&) = delete;
    Dog& operator=(const Dog&) = delete;
};
*/


int main() {
    Animal* pet = new Dog;
    pet->speak();       // Calls Dog::speak()
    delete pet;         // Calls ~Dog(), then ~Animal()
	pet = nullptr;      // Avoid leaving a dangling value in pet.
}
