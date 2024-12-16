#pragma once
#include<iostream>
#include <array>
#include <random>


using namespace std;

constexpr array<double, 4> EMPTY = { 0.0,0.0,0.0,0.0 };
constexpr array<double, 4> WALL = { -1.0,-1.0,-1.0,-1.0 };
constexpr double RELAVATION_TIME = 0.75;

class Cell {
private:
    array <double, 4> info;

public:
    Cell();
    Cell(array<double,4>);

    void set_info(array<double,4>);
    const array<double,4>& get_info() const;
    
    double calculate_density();
    double calculate_fun_eq();
    array < double, 4> calculate_fun_exit();
};