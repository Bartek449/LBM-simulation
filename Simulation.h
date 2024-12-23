#pragma once
#include "Matrix.h"

class Simulation {
private:
    Matrix s;
public:
    Simulation(int, int);

    Matrix& get_matrix();

    void streaming();
};