#include <iostream>
using namespace std;
int main(){
    //string literal
    char str[10]="Aditya" ;
    cout<<"input str: "<<str<<endl;
    //we have to make the string uppercase by using the ascii values:
    for(int i=0 ; str[i]!='\0' ; i++){
        if(str[i]>=97 && str[i]<=122){
            str[i]=str[i]-32 ;
        }
        // if there is any uppercase letter or special character:
        else if(str[i]>=65 && str[i]<=90){
            str[i]=str[i] ;
        }
        else{
            str[i]=str[i] ;
        }
    }
    cout<<"Answer str: "<<str<<endl;

    
}