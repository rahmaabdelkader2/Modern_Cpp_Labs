#include <iostream>

class Vector {
    
    private:
    int* data;
    int size;
    int capacity;
    
    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    
    public:
    Vector(){
     //data=nullptr;
     size=0;
     capacity=1;
     data = new int[capacity]; 
        }
    void push_back(int value){
        if(size>=capacity){
            resize(capacity*2);
        }
        data[size++]=value;
    }
    
     void pop_back() {
        if (size == 0) {
            std::printf("Size is already zero");
        }
        --size;
    }
    
     
    int  getSize() const {
        return size;
    }


    int getCapacity() const {
        return capacity;
    }
    
    void print() const {
        std::cout << "vector elements: ";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    
    ~Vector() {
        delete[] data;
    }
    
};




int main() {
     Vector vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
   // triggering resize
    vec.push_back(40);
    vec.push_back(30);


    vec.print(); 
    std::cout << "Size: " << vec.getSize() << std::endl;     
    std::cout << "Capacity: " << vec.getCapacity() << std::endl; 

    vec.pop_back();
    vec.print(); 

    return ;
}
