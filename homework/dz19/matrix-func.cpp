#include "matrix.h"
#include <iostream>
#include <algorithm>
using namespace std;

Matrix::Matrix(int rows, int cols){
    this -> rows = rows;
    this -> cols = cols;

    data = new int*[rows];
    for (int i=0; i<rows; i++){
        data[i] = new int[cols];
        for (int j=0; j<cols; j++){
            data[i][j] = 0;
        }
    }
}

Matrix::~Matrix(){
    for (int i=0; i<rows; i++){
        delete[] data[i];
    }
    delete[] data;
}

Matrix::Matrix(const Matrix& other){
    rows = other.rows;
    cols = other.cols;

    data = new int*[rows];
    for (int i=0; i<rows; i++){
        data[i] = new int[cols];
        for (int j=0; j<cols; j++){
            data[i][j] = other.data[i][j];
        }
    }
}

int Matrix::getRows() const{
    return rows;
}

int Matrix::getCols() const{
    return cols;
}

int& Matrix::operator()(int row_i, int col_i){
    if (row_i < 0 || row_i >= rows || col_i < 0 || col_i >= cols) {
        throw std::out_of_range("Out of range.");
    }
    return data[row_i][col_i];
}

const int& Matrix::operator()(int row_i, int col_i) const{
    if (row_i < 0 || row_i >= rows || col_i < 0 || col_i >= cols) {
        throw std::out_of_range("Out of range.");
    }
    return data[row_i][col_i];
}

void Matrix::resize(int new_rows, int new_cols){
    if (new_rows <= 0 || new_cols <= 0){
        throw std::invalid_argument("Invalid argument");
    }
    if (new_rows == rows && new_cols == cols){
        return; 
    }

    int** new_data = new int*[new_rows];
    for (int i=0; i<new_rows; i++){
        new_data[i] = new int[new_cols];
        for (int j=0; j<new_cols; j++){
            new_data[i][j] = 0;
        }
    }

    int copy_rows = min(rows, new_rows);
    int copy_cols = min(cols, new_cols);
    for (int i=0; i<copy_rows; i++){
        for (int j=0; j<copy_cols; j++){
            new_data[i][j] = data[i][j];
        }
    }

    for (int i=0; i<rows; i++){
        delete data[i];
    }
    delete[] data;

    data = new_data;
    rows = new_rows;
    cols = new_cols;
}