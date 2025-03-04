#pragma once
#include "Borrowable.hpp"

class Book:public Borrowable
{
    private:
        std::string bookName;
        int bookId;
        std::string bookAuthor;
        bool isAvaiable;
   public:
       Book(std::string bookName, int bookId, std::string bookAuthor);
       
       //getter function
       void displayBookInfo() const;
       
       bool checkAvailability() const;
       
       void borrowBook() ;
       void returnBook() ;
       
       ~Book(){};
       
    
};