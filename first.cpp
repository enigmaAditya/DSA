#include<iostream>
using namespace std;

int main() {
    // cout << "Namaste Bharat" << endl ;
    // cout << '1' << endl;

    // int a;
    // cout << "Enter a number: ";
    // cin >> a;
    // cout << "You entered: " << a << endl;

    // int a = 5;
    // cout <<"Value of a is: " << a << endl;

    // char ch = 69;
    // cout << "Value of ch is: " << ch << endl;

    // bool flag = true;
    // cout << "Value  of flag is: " << flag << endl;

    // float f = 1.2;
    // cout << "Value of f is: " << f<< endl;

    // double d =1.2;
    // cout << "Value of d is: " << d<< endl;

//Conditionals:
    // int score;
    // cout << "Enter the score: " << endl;
    // cin >> score;
    // if(score<300){
    //     cout << "India Wins." << endl;
    // }
    // else{
    //     cout << "Pak wins." << endl;
    // }

//If - else if - else:
    // int marks;
    // cout << "Enter The marks: ";
    // cin >> marks;
    // if(marks>=90){
    //     cout <<"A Grade" << endl;
    // }
    // else if(marks>=80){
    //     cout <<"B Grade"<< endl;
    // }
    // else if(marks>=70){
    //     cout << "C Grade"<< endl;
    // }
    // else if(marks>=60){
    //     cout << "D Grade" << endl;
    // }
    // else if(marks>=40){
    //     cout << "E Grade"<< endl;
    // }
    // else{
    //     cout << "F grade" << endl;
    // }

//for Loop:
    for(int i=0; i<5; i++){
        cout << "Aditya is Mad" << endl;
    }
    cout << ".........."<< endl;
    for(int i = 0; i<3; i++){
        cout << i << endl;
    }
    cout << ".........."<< endl;
    for(int i=5; i>0; i--){
        cout << i << endl;
    }
    cout << ".........."<< endl;
    for(int i =1; i<=10; i++){
        cout << 2*i << endl;
    }
    cout << ".........."<< endl;
    for(int i=0; i<=5; i=i+2){
        cout << i << endl;
    }
    cout << ".........."<< endl;
    for(int i = 1; i<=5; i=i+2){
        cout << i << endl;
    }
    cout << ".........."<< endl;
    for(int i = 1; i<10; i=i*2){
        cout << i << endl;
    }
    cout << ".........."<< endl;
    for(int i = 100; i>0; i=i/2){
        cout << i << endl;
    }
    cout << ".........."<< endl;
    for(int i = 5; (i>=0 && i<=10); i=i+1){
        cout << i << endl; 
    }
    cout << ".........."<< endl;
    for(int r=0; r<3; r++){
        for(int c=0; c<5; c++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << ".........."<< endl;
    
    return 0;

}