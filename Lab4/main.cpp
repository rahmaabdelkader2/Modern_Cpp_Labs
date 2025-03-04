#include "Library.hpp"
#include "Student.hpp"
#include "Teacher.hpp"

int main()
{
	Library lib;
	lib.addBook(Book("C++ Book",123,"try"));
	lib.addBook(Book("Linux Book",456,"diff"));
	lib.addBook(Book("Android Book",789,"oop concepts"));
	
	lib.addUser(new Student("user1",100));
	lib.addUser(new Teacher("user2",250));
	
	lib.displayBooks();
	
	return 0;
}
