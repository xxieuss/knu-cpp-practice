#pragma once

class Matrix{
    int rows;
    int cols;
    int** data;

public:
    Matrix(int rows, int cols);
    ~Matrix();
    Matrix(const Matrix& other);

    int getRows() const;
    int getCols() const;

    int& operator()(int row_i, int col_i);
    const int& operator()(int row_i, int col_i) const;

    void resize(int new_rows, int new_cols);
};