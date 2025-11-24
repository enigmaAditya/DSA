// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std ;

template<typename T>
class List {
    
    // pure virtual functions 
    // abstract class is which contains at least one pure virtual function 
    // abstract class can't be intansiated , Object cant be created 
    virtual void push_back(T x) = 0;
    virtual void pop_back()  = 0;
    virtual void insert(T x , int pos) =  0;
    virtual void pop_back(int pos) = 0 ;
} ;

// inheritance 
// 1) public :  access modifier will not be changed in child class 
// 2) protected :  public ---> protected 
// 3) private :  public , protected ---> private 
template<typename T>
class ArrayList : public   List<T> {
    private :
    T* arr ;
    int size  ;
    int capacity ;
    
    public :
    
    // constrcutor 
    ArrayList(int capacity = 5){
        this->arr = new T[capacity] ;
        this->size = 0 ;
        this->capacity = capacity ;
    }
    // copy construcutor 
    
    
    T operator [] (int pos){
        if (pos >= size || pos <0){
            cout<<"Invalid index" ;
            return -1 ;
        }
        return this->arr[pos] ;
    }
    
    void push_back(T x){
        arr[this->size++] = x ;
    }
    
    void pop_back(){ 
        this->size-- ;
    }
    
    // 
    
   void insert(T x , int pos) ;
   void pop_back(int pos);
    
    
    
    
    
};

int main() {
    // Write C++ code here

    return 0;
}


