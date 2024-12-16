#pragma once
#include "Cell.h"


class Matrix{
private:
    int rows, columns;
    vector <vector <Cell> > element;

public:
    Matrix();
    Matrix(int, int);
    Matrix(const Matrix&);

    Cell& get_element(int, int);
    int get_rows_num() const;
    int get_columns_num() const;
    void prepare_environment();
};
