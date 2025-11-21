#include<bits/stdc++.h>
using namespace std;
template<typename T>
class MyVector{
private:
    T* arr;
    int capacity;
    int size;

    void resize(){
        this->capacity *=2;
        T * temp = new T[capacity];
        for(int i=0;i<size;i++){
            temp[i]=arr[i];
        }
        delete[] arr;
        this->arr = temp;

    }
public:
    MyVector(int capacity =10){
        this->capacity = capacity;
        this->size = 0;
        this->arr= new T[capacity];
    }

     
    void push_back(T x){
        if(size==capacity){
            this->resize();
        }   
        this->arr[this->size++] = x;
    }

    void pop_back(){
        this->size--;
    }

    T operator [](int index){
        return this->arr[index];
    }

    int get_size(){
       return this->size;
    }

};

class List{
private:

};
int main(){
    MyVector<float>arr;
    float n;
    cin>>n;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(n);
    arr.push_back(5);
    arr.pop_back();

   for(int i=0; i<arr.get_size();i++){
    cout<<arr[i]<<" ";
   }
    return 0;
    

}