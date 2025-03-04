#pragma once
#include"Book.hpp"
#include "User.hpp"
#include <vector>

class Library
{
	private :
	
		std::vector<Book> books; // Composition relation between Library and Book
		std::vector<User*> users; // Aggregation relation between Library and User
	public:
		void addBook(const Book& book);
		void addUser(User* user);
		void displayBooks() const;
		void displayUsers() const;
	~Library();

};