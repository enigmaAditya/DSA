#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[20];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        // int a = arr[i];
        for(int j=0;j<arr[i];j++){
            cout<<"X ";
        }
        cout<<endl; 
    }
}