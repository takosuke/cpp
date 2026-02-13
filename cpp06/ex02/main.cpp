#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* createA() { return new A(); }
Base* createB() { return new B(); }
Base* createC() { return new C(); }

Base* generate()
{
	typedef Base* (*Creator)();
	Creator creators[] = { createA, createB, createC };
	int r = rand() % 3;
	Base* obj = creators[r]();
	return (obj);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer p is of class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer p is of class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer p is of class C" << std::endl;
}

void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Ref r is of class A" << std::endl;
		return ;
	}
	catch (std::exception& e) {
	}
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Ref r is of class B" << std::endl;
		return ;
	}
	catch (std::exception& e) {
	}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Ref r is of class C" << std::endl;
		return ;
	}
	catch (std::exception& e) {
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	Base *p = generate();
	identify(p);
	Base& r = *p;
	identify(r);
	delete p;
	return 0;
}
