# Unique_ptr
**Team Members`**
 * Stepanyan Mery
 * Aslanyan Mamikon
 * Lazaryan Nane
 * Arakelyan Anna
 * Galstyan Anna
 * Sharopetrosyan Mane

**Overview:**
This project demonstrates a custom implementation of a unique pointer (u_ptr) in C++.
* The u_ptr class manages a dynamically allocated object, ensuring proper memory management through RAII (Resource Acquisition Is Initialization) principles.
* The class supports move semantics to transfer ownership but prohibits copy operations, similar to std::unique_ptr.
* Copy constructor and copy assignment are deleted to avoid accidental sharing of ownership.
* Implements operator-> and operator* to access the managed object.

The Car class demonstrates how u_ptr can be used with user-defined types.
This project illustrates the core principles behind std:: unique_ptr while providing a hands-on approach to understanding smart pointers and memory management in C++.
