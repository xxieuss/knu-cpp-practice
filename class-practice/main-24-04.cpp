#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <concepts>
using namespace std;

template <typename T>
concept Numeric = integral<T> || floating_point<T>;
template <typename T>
concept Printable = requires(ostream& os, const T& value){
    os << value;
};

template <Numeric T>
vector<vector<T>> matrix_multiplication(const vector<vector<T>>& A, const vector<vector<T>>& B){
    if (A.empty() || B.empty() || A[0].empty() || B[0].empty()){
        throw invalid_argument("Matrices can't be empty");
    }
    size_t rowsA = A.size();
    size_t colsA = A[0].size();
    size_t rowsB = B.size();
    size_t colsB = B[0].size();
    if (colsA != rowsB){
        throw invalid_argument("Invalid dimensions");
    }

    vector<vector<T>> result(rowsA, vector<T>(colsB, 0));
    for (size_t i=0; i<rowsA; i++){
        for (size_t j=0; j<colsB; j++){
            for (size_t n=0; n<colsA; n++){
                result[i][j] += A[i][n] * B[n][j];
            }
        }
    }
    return result;
}

template <Printable T>
void print(const vector<vector<T>>& matrix){
    for (const auto& row : matrix){
        for (const auto& el : row){
            cout << setw(8) << el << " ";
        }
        cout << endl;
    }
}

int main(){
    try{
        cout << "For integer matrix:" << endl;
        vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}};
        vector<vector<int>> B = {{7, 8}, {9, 10}, {11, 12}};
        vector<vector<int>> int_res = matrix_multiplication(A, B);
        cout << "Result:" << endl;
        print(int_res);
        cout << endl;

        cout << "For double matrix:" << endl;
        vector<vector<double>> C = {{1.5, 2.5, 3.0}, {4.4, 5.5, 6.6}};
        vector<vector<double>> D = {{7.5, 8.9}, {9.9, 10.0}, {11.1, 12.2}};
        vector<vector<double>> double_res = matrix_multiplication(C, D);
        cout << "Result:" << endl;
        print(double_res);
        cout << endl;

        cout << "Test exception:" << endl;
        matrix_multiplication(A, A);
    } catch (const exception& e){
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}