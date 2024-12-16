#pragma once
#include<iostream>
#include <array>
#include <random>

using namespace std;

constexpr array<double, 4> EMPTY = { 0.0,0.0,0.0,0.0 };
constexpr array<double, 4> STARTING_STATE = { 0.25,0.25,0.25,0.25 };
constexpr array<double, 4> WALL = { -1.0,-1.0,-1.0,-1.0 };

constexpr double RELAXATION_TIME = 0.75;

class Cell {
private:
    array <double, 4> fun_in;

public:
    Cell();
    Cell(array<double,4>);

    void set_fun_in(array<double,4>);
    void set_direct_fun_in(int, double);
    const array<double,4>& get_fun_in() const;
    
    double calculate_density();
    double calculate_fun_eq();
    array < double, 4> calculate_fun_ex();
};
