#include <iostream>
using namespace std;
string substring(string str,int j, int size){
    string res = "";
    for(int i=j; i<=j+size; i++){
        res+=str[i];
    }
    return res;
}

int find(string main, string word){
    int n = main.length();
    int m = word.length();
    for(int i=0; i<=n-m; i++){
        int j;
        for(j=0; j<m; j++){
            if(main[i+j]!=word[j]){
                break;
            }
        }
        if(j==m){
            return i;
        }
    }
    return -1;
}

string replace(string main, string old, string word){
    string result = "";
    int i = 0;

    while(i < main.length()){
        if(main.substr(i, old.length()) == old){
            result += word;
            i += old.length();
        } else {
            result += main[i];
            i++;
        }
    }
    return result;//output : Aditya is a awesome
}

string erase_substring(string main, string del){
    string result = "";
    int i = 0;
    while(i < main.length()){
        if(main.substr(i, del.length()) == del){
            i += del.length();
        } else {
            result += main[i];
            i++;
        }
    }
    return result;//output : Aditya is a boy
}

//different string functions inbuilt
//1. length() - returns the length of the string
//2. find() - returns the index of the first occurrence of a substring
//3. substr() - returns a substring from the string
//4. replace() - replaces a substring with another substring
//5. erase() - removes a substring from the string
//6. append() - adds a substring at the end of the string
//7. insert() - inserts a substring at a specified position in the string
//8. clear() - removes all characters from the string
//9. empty() - checks if the string is empty
//10. at() - returns the character at a specified position in the string
//11. c_str() - returns a pointer to a null-terminated character array
//12. stoi() - converts a string to an integer
//13. to_string() - converts an integer to a string
//14. compare() - compares two strings
//15. swap() - swaps the contents of two strings
//16. pop_back() - removes the last character from the string
//17. push_back() - adds a character at the end of the string
//18. resize() - changes the size of the string
//19. capacity() - returns the size of the allocated storage space for the string
//20. reserve() - requests a change in the capacity of the string
//21. shrink_to_fit() - reduces the capacity of the string to fit its size
//22. front() - returns the first character of the string
//23. back() - returns the last character of the string
//24. find_first_of() - returns the index of the first occurrence of any character from a set
//25. find_last_of() - returns the index of the last occurrence of any character from a set
//26. find_first_not_of() - returns the index of the first occurrence of a character not in a set
//27. find_last_not_of() - returns the index of the last occurrence of a character not in a set



int main(){
    //string literal
    char *str="Aditya" ;
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
    cout<<"Answer str: "<<str<<endl; //output : ADITYA


    //split functionality
    string s = "Aditya is learning C++" ;
    string w[10] ;
    int k=0 ;
    int n = s.length();
    string curr_word = "" ;
    for(int i=0 ; i<n ; i++){
        if(s[i]==' '){
            w[k]=curr_word ;
            curr_word="" ;
            k++ ;
        }
        else{
            curr_word+=s[i] ;
        }
    } 
   w[k]=curr_word;
   for(int i=0 ; i<=k ; i++){
       cout<<w[i]<<endl; //output : Aditya \n is \n learning \n C++
   }

   //substring functionality
    string str1 = "Aditya is a good boy" ;
    string sub = substring(str1,8, 2); //output:
    cout<<"Substring is: "<<sub<<endl;
    return 0 ;

    int f1 = str1.find("good");
    cout<<"The index of good is: "<<f1<<endl;//output: The index of good is: 10
    //find function call:
    int f2 = find(str1, "good");
    cout<<"The index of good is: "<<f2<<endl;//output: The index of good is: 10
    //replaced function call:
    string replaced_str = replace(str1, "good", "awesome");
    cout<<"Replaced string is: "<<replaced_str<<endl;//output : Aditya is a awesome
    //erase function call:
    string erased_str = erase_substring(str1, "good ");
    cout<<"Erased string is: "<<erased_str<<endl;//output : Aditya is a boy
    
   }
