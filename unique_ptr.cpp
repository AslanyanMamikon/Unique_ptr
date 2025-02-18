// smart_ptr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <typename Type>
class u_ptr {
public:
    u_ptr() : uData(nullptr) { cout << "default constr" << endl; }
	u_ptr(Type* ptr) : uData(ptr) { cout << "u_Ptr constr" << endl; }
	~u_ptr()
    {
        delete uData;
        uData = nullptr;
        cout << "destructor" << endl;
    }

	u_ptr(const u_ptr& obj) = delete;
	u_ptr& operator=(const u_ptr& obj) = delete;

	// move constructor
	u_ptr(u_ptr&& otherPtr) noexcept
	{
		this->uData = otherPtr.uData;
        otherPtr.uData = nullptr;
        cout << "move constr" << endl;
	}

	// move assignment
	u_ptr& operator=(u_ptr&& otherPtr) noexcept
	{
        if (this != &otherPtr) {
            delete uData;
            uData = otherPtr.uData;
            otherPtr.uData = nullptr;
        }
        cout << "move assignment" << endl;
        return *this;
	}

	Type* operator->()
	{
		return this->uData;
	}

	Type& operator*()
	{
		return *(this->uData);
	}

    Type* get() const
    {
        return uData; 
    }

private:
	Type* uData = nullptr;
};

class Car {
private:
    string brand;
    int year;

public:
    Car(const string& brand, int year)
        : brand(brand)
        , year(year)
    {
    }

    void display() const
    {
        cout << "Brand: " << brand << ", Year: " << year
            << endl;
    }
};

template <typename Type, typename A>
u_ptr<Type> make_u(int i, A&& a)
{
    return u_ptr<Type>{new Type{ i,forward<A>(a) }};
}

int main()
{
    u_ptr<Car> carPtr(new Car("Toyota", 2022));
    carPtr->display(); 

    u_ptr<Car> newCarPtr;
    newCarPtr = move(carPtr);
    cout << endl << "......................" << endl;

    if (newCarPtr.get() != nullptr) {
        newCarPtr->display();
    }
    else {
        cout << "No Car object available." << endl;
    }

    if (carPtr.get() != nullptr) {
        carPtr->display();
    }
    else {
        cout << "No Car object available (P1)." << endl;
    }
    cout << "......................" << endl;
    u_ptr<int> p1(new int(33));
    if (p1.get() != nullptr) {
        cout << *p1 << endl;
    }
    else {
        cout << "P1 is not avalible" << endl;
    }
    u_ptr<int> p2(move(p1));

    if (p2.get() != nullptr) {
        cout << *p2 << endl;
    }
    else {
        cout << "P1 is not avalible" << endl;
    }
    cout << "......................" << endl;
    
    return 0;
}
