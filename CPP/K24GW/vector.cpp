#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    vector <int> arr;
    arr.push_back(10);
    //vector inbuilt functions:
    //1. push_back(): Adds an element to the end of the vector.
    arr.push_back(20);
    //2. pop_back(): Removes the last element from the vector.
    arr.pop_back();
    //3. size(): Returns the number of elements in the vector.
    int n = arr.size();
    //4. at(index): Returns the element at the specified index with bounds checking.
    int firstElement = arr.at(0);
    //5. operator[]: Returns the element at the specified index without bounds checking.
    int secondElement = arr[1];
    //6. clear(): Removes all elements from the vector.
    arr.clear();
    //reverse a vector:
    reverse(arr.begin(), arr.end());
    //reverse a part of vector:
    reverse(arr.begin(), arr.begin() + 2);//explain: this will reverse first two elements of vector

    //leetcode 189: Rotate Array
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    k = k % nums.size(); //in case k is greater than size of array
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    //after above three reverse operations, the array will be rotated by k positions to the right
    //print the rotated array
    for(int i = 0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }

    //sorting using stl:
    vector<int> vec = {4, 2, 5, 1, 3};
    sort(vec.begin(), vec.end()); //sort in ascending order
    cout << "\nSorted vector: ";
    for(int i = 0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }

    //sorting a part of vector:
    vector<int> vec2 = {4, 2, 5, 1, 3};
    sort(vec2.begin(), vec2.begin() + 3); //sort first three elements
    return 0;
}