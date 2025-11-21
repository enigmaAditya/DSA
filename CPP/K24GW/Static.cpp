#include<iostream>
#include<bits/stdc++.h>
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
    //leetcode 867 solve: Transpose the given matrix:
    //use vector of vector to store the matrix:
    vector<vector<int>> matrix(n);
    for(int i=0;i<n;i++){
        matrix[i].resize(arr[i]);
        for(int j=0;j<arr[i];j++){
            cin>>matrix[i][j];
        }
    }
    //transpose the matrix:
    vector<vector<int>> transpose(arr[0], vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<arr[i];j++){
            transpose[j][i] = matrix[i][j];
        }
    }
    //print the transposed matrix:
    for(int i=0;i<transpose.size();i++){
        for(int j=0;j<transpose[i].size();j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }

}