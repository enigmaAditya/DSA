//Operator Overloading in C++
#include <iostream>
using namespace std;

// class Complex {
//     private:
//         float real;
//         float imag;
//     public:
//         Complex(float r = 0, float i = 0) : real(r), imag(i) {}
//         // Overloading the + operator
//         Complex operator + (const Complex& obj) {
//             return Complex(real + obj.real, imag + obj.imag);
//         }
//         Complex operator - (const Complex& obj){
//             return Complex(real - obj.real, imag - obj.imag);
//         }
//         Complex operator * (const Complex& obj){
//             return Complex(real * obj.real - imag * obj.imag, real * obj.imag + imag * obj.real);
//         }   
//         Complex operator / (const Complex& obj){
//             float denom = obj.real * obj.real + obj.imag * obj.imag;
//             return Complex((real * obj.real + imag * obj.imag) / denom,
//                            (imag * obj.real - real * obj.imag) / denom);
//         }
//         //dot product of two complex numbers
//         float operator % (const Complex& obj){
//             return real * obj.real + imag * obj.imag;
//         }
//         //cross product of two complex numbers
//         float operator ^ (const Complex& obj){
//             return real * obj.imag - imag * obj.real;
//         }
//         // Overloading the == operator
//         bool operator == (const Complex& obj) {
//             return (real == obj.real && imag == obj.imag);
//         }

//         // // Overloading the << operator for output
//         // friend ostream& operator << (ostream& out, const Complex& obj) {
//         //     out << obj.real << " + " << obj.imag << "i";
//         //     return out;
//         // }
//         // // Overloading the >> operator for input
//         // friend istream& operator >> (istream& in, Complex& obj) {
//         //     in >> obj.real >> obj.imag;
//         //     return in;
//         // }

//         // Overloading the greater than operator
//         bool operator > (const Complex& obj) {
//             return (real * real + imag * imag) > (obj.real * obj.real + obj.imag * obj.imag);
//         }
//         // Overloading the less than operator
//         bool operator < (const Complex& obj) {
//             return (real * real + imag * imag) < (obj.real * obj.real + obj.imag * obj.imag);
//         }
//         // Overloading the >= operator
//         bool operator >= (const Complex& obj) {
//             return (real * real + imag * imag) >= (obj.real * obj.real + obj.imag * obj.imag);
//         }
//         // Overloading the <= operator
//         bool operator <= (const Complex& obj) {
//             return (real * real + imag * imag) <= (obj.real * obj.real + obj.imag * obj.imag);
//         }
//         // Overloading the != operator
//         bool operator != (const Complex& obj) {
//             return (real != obj.real || imag != obj.imag);
//         }
//         // Overloading the -- operator (postfix)
//         Complex operator -- (int) { //postfix decrement
//             Complex temp = *this;
//             real--;
//             imag--;
//             return temp;
//         }
//         // Overloading the ++ operator (prefix)
//         Complex operator ++ (){ //prefix increment
//             real++;
//             imag++;
//             return *this;
//         }

//         void display() {
//             cout << "Real: " << real << ", Imaginary: " << imag << endl;
//         }
// };

//vector all operator functions using operator overloading
// class Vector {
//     private:
//         float x, y, z;
//     public:
//         Vector(float a = 0, float b = 0, float c = 0) : x(a), y(b), z(c) {}
        
//         // Overloading the + operator for vector addition
//         Vector operator + (const Vector& obj) {
//             return Vector(x + obj.x, y + obj.y, z + obj.z);
//         }

//         // Overloading the - operator for vector subtraction
//         Vector operator - (const Vector& obj) {
//             return Vector(x - obj.x, y - obj.y, z - obj.z);
//         }

//         // Overloading the * operator for scalar multiplication
//         Vector operator * (float scalar) {
//             return Vector(x * scalar, y * scalar, z * scalar);
//         }

//         // Overloading the % operator for dot product
//         float operator % (const Vector& obj) {
//             return x * obj.x + y * obj.y + z * obj.z;
//         }

//         // Overloading the ^ operator for cross product
//         Vector operator ^ (const Vector& obj) {
//             return Vector(y * obj.z - z * obj.y,
//                           z * obj.x - x * obj.z,
//                           x * obj.y - y * obj.x);
//         }
//         // Overloading the == operator for equality check
//         bool operator == (const Vector& obj) {
//             return (x == obj.x && y == obj.y && z == obj.z);
//         }
//         // Overloading the < operator for magnitude comparison
//         bool operator < (const Vector& obj) {
//             return (x * x + y * y + z * z) < (obj.x * obj.x + obj.y * obj.y + obj.z * obj.z);
//         }
//         // Overloading the > operator for magnitude comparison
//         bool operator > (const Vector& obj) {
//             return (x * x + y * y + z * z) > (obj.x * obj.x + obj.y * obj.y + obj.z * obj.z);
//         }
//         // Overloading the != operator for inequality check
//         bool operator != (const Vector& obj) {
//             return (x != obj.x || y != obj.y || z != obj.z);
//         }
//         // Overloading the -- operator (postfix)
//         Vector operator -- (int) { //postfix decrement  
//             Vector temp = *this;
//             x--;
//             y--;
//             z--;
//             return temp;
//         }
//         // Overloading the ++ operator (prefix)
//         Vector operator ++ (){ //prefix increment
//             x++;
//             y++;
//             z++;
//             return *this;
//         }
//         // Function to display vector
//         void display() {
//             cout << "Vector(" << x << ", " << y << ", " << z << ")" << endl;
//         }
// };


//for what else i can use operator overloading in c++ : suggestions
//1. String concatenation
//2. Matrix operations
//3. Custom smart pointers
//4. Complex number operations (as shown above)
//5. Rational number arithmetic
//6. Date and time manipulations
//7. File stream operations
//8. Mathematical vector and matrix operations
//9. Geometric transformations
//10. User-defined data structures (like linked lists, trees, etc.)
//11. Bitwise operations for custom data types
//12. Logical operations for custom boolean types
//13. Resource management classes (like memory pools)
//14. Graph data structures and algorithms
//15. Event handling systems
//16. Game development (e.g., vector math, entity management)
//17. Physics simulations (e.g., force and velocity calculations)
//18. Financial calculations (e.g., currency operations)
//19. Networking (e.g., packet manipulation)
//20. GUI frameworks (e.g., widget manipulation)
//These are just a few examples; operator overloading can be applied in many other contexts depending on the requirements of the application.
// Example usage
//Matrix every possible operations using operator overloading
class Matrix {
    private:
        int rows, cols;
        int** data;
    public:
        Matrix(int r, int c) : rows(r), cols(c) {
            data = new int*[rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    data[i][j] = 0;
                }
            }
        }
        // Overloading the + operator for matrix addition
        Matrix operator + (const Matrix& obj) {
            Matrix result(rows, cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.data[i][j] = data[i][j] + obj.data[i][j];
                }
            }
            return result;
        }
        // Overloading the - operator for matrix subtraction
        Matrix operator - (const Matrix& obj) {
            Matrix result(rows, cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.data[i][j] = data[i][j] - obj.data[i][j];
                }
            }
            return result;
        }
        // Overloading the * operator for matrix multiplication
        Matrix operator * (const Matrix& obj) {
            Matrix result(rows, obj.cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < obj.cols; j++) {
                    for (int k = 0; k < cols; k++) {
                        result.data[i][j] += data[i][k] * obj.data[k][j];
                    }
                }
            }
            return result;
        }
        // Overloading the == operator for matrix equality check
        bool operator == (const Matrix& obj) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (data[i][j] != obj.data[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        }
        // Overloading the != operator for matrix inequality check
        bool operator != (const Matrix& obj) {
            return !(*this == obj);
        }
        // can we transpose a matrix using operator overloading
        Matrix operator ~ () { //transpose operator
            Matrix result(cols, rows);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.data[j][i] = data[i][j];
                }
            }
            return result;
        }
        // Function to display matrix
        void display() {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << data[i][j] << " ";
                }
                cout << endl;
            }
        }
};
int main() {
    // Complex c1(3.5, 2.5), c2(1.5, 4.5);
    // Complex c3 = c1 + c2; // Using overloaded + operator
    // c3.display();

    // // Vector operations
    // Vector v1(1, 2, 3), v2(4, 5, 6);
    // Vector v3 = v1 + v2; // Using overloaded + operator
    // v3.display();
    // Matrix operations
    Matrix m1(2, 2), m2(2, 2);
    //take input for m1 and m2 from user
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            
        }
    }

    m1 = m1 + m2; // Using overloaded + operator
    m1.display();
    Matrix m3 = ~m1; // Transpose back to original
    m3.display();// Output the transposed matrix
    //output:
    //0 0 explaination: m1 is a 2x2 matrix initialized with zeros. When we transpose it, the result is still a 2x2 matrix of zeros.
    return 0;
}