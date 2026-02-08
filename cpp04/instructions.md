Since I cannot provide a direct file download link, here is the transcription formatted in clean Markdown. You can easily copy and paste this into a .md file.

Chapter II: General rules

Compiling

    Compile your code with c++ and the flags -Wall -Wextra -Werror.

    Your code should still compile if you add the flag -std=c++98.

Formatting and naming conventions

    The exercise directories will be named this way: ex00, ex01, ... exn.

    Name your files, classes, functions, member functions and attributes as required in the guidelines.

    Write class names in UpperCamelCase format.

    Files containing class code will always be named according to the class name. For instance: ClassName.hpp/ClassName.h, ClassName.cpp, or ClassName.tpp.

    Unless specified otherwise, every output message must end with a newline character and be displayed to the standard output.

    Goodbye Norminette! No coding style is enforced in the C++ modules. You can follow your favorite one.

    Do your best to write clean and readable code.

Allowed/Forbidden

    You are allowed to use almost everything from the standard library.

    However, you can’t use any other external library. This means C++11 (and derived forms) and Boost libraries are forbidden.

    The following functions are forbidden: *printf(), *alloc() and free(). Use of these results in a grade of 0.

    Unless explicitly stated otherwise, the using namespace <ns_name> and friend keywords are forbidden. Violation results in a grade of -42.

    You are allowed to use the STL only in Modules 08 and 09. No containers or algorithms are allowed before then.

Design requirements

    You must avoid memory leaks when using the new keyword.

    From Module 02 to Module 09, your classes must be designed in the Orthodox Canonical Form, except when explicitly stated otherwise.

    Any function implementation put in a header file (except for function templates) means 0 to the exercise.

    Headers must include all the dependencies they need and must use include guards.

Chapter IV: Exercise 00: Polymorphism
Field	Value
Exercise	

00

Turn-in directory
	

ex00/
Files to turn in	

Makefile, main.cpp, *.cpp, *.{h, hpp}
Forbidden functions	

None

    Provide the most complete tests possible.

    Constructors and destructors of each class must display specific, unique messages.

    Implement a base class Animal with a protected attribute std::string type;.

    Implement Dog and Cat classes that inherit from Animal.

    Dog's type must be "Dog"; Cat's type must be "Cat".

    Every animal must have a makeSound() member function that prints an appropriate sound.

    To test polymorphism, implement a WrongCat class inheriting from a WrongAnimal class where the sound output does not correctly override.

Chapter V: Exercise 01: I don’t want to set the world on fire
Field	Value
Exercise	01
Turn-in directory	ex01/
Files to turn in	Files from previous exercise + *.cpp, *.{h, hpp}
Forbidden functions	None

    Implement a Brain class containing an array of 100 std::string called ideas.

    Dog and Cat will have a private Brain* attribute.

    They must create their Brain via new Brain() on construction and delete it on destruction.

    Create an array of Animal objects (half Dogs, half Cats) and delete them at the end.

    Destructors must be called in the correct order.

    Copies of Dogs or Cats must not be shallow; you must prove deep copies in your tests.

Chapter VI: Exercise 02: Abstract class
Field	Value
Exercise	02
Turn-in directory	ex02/
Files to turn in	Files from previous exercise + *.cpp, *.{h, hpp}
Forbidden functions	None

    The Animal class should no longer be instantiable.

    Fix the class so nobody can instantiate it, while keeping everything else working.

    You may optionally prefix the class name as AAnimal.

Chapter VII: Exercise 03: Interface & recap
Field	Value
Exercise	03
Turn-in directory	ex03/
Files to turn in	Makefile, main.cpp, *.cpp, *.{h, hpp}
Forbidden functions	None

    Implement a pure abstract class (interface) AMateria.

    Implement concrete Materias: Ice (type "ice") and Cure (type "cure").

    clone() must return a new instance of the same type.

    use(ICharacter&) displays:

        Ice: "* shoots an ice bolt at <name> *"

        Cure: "* heals <name>’s wounds *" 

    Implement a Character class with an inventory of 4 slots.

    unequip() must NOT delete the Materia. You must handle potential memory leaks for items left on the floor.

    Characters must perform deep copies; old Materias must be deleted before new ones are added during assignment.

    Implement MateriaSource which can "learn" and "create" Materias based on string types.
