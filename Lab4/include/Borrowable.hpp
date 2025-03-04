#include <iostream>
class Borrowable
{
    private:
        std::string itemName; 
        std::string borrowDate;
    public :
        virtual ~Borrowable() {};
}; 
