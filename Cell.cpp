#include"Cell.h"

Cell::Cell() : fun_in(EMPTY), fun_ex(EMPTY), fun_eq(EMPTY), density(0), weight(0.25) {}

Cell::Cell(array<double, 4> i) : fun_in(i), fun_ex(EMPTY), fun_eq(EMPTY), density(0), weight(0.25) {
    calculate_density();
}

void Cell::set_fun(FunType f, array<double,4> i) {
    if(f == FUN_IN) fun_in = i;
    else if (f == FUN_EX) fun_ex = i;
    else if (f == FUN_EQ) fun_eq = i;
}

void Cell::set_direct_fun(FunType f, int index, double num) {
    if (f == FUN_IN)fun_in[index] = num;
    else if (f == FUN_EX) fun_ex[index] = num;
    else if (f == FUN_EQ) fun_eq[index] = num;
}

const array<double,4>& Cell::get_fun(FunType f) const { 
    if (f == FUN_IN) return fun_in;
    else if (f == FUN_EX) return fun_ex;
    else if (f == FUN_EQ) return fun_eq;;
}

void Cell::calculate_density()
{
    density = 0;
    for (const auto& val : fun_in)
    {
        density += val;
    }

}

double Cell::get_density() { return density; }


void Cell::calculate_fun_eq() { 
    for (int i = 0; i < 4; ++i) {
        fun_eq[i] = density * weight;
    } 
}

void Cell::calculate_fun_ex() 
{ 
    calculate_fun_eq();
    for (int i = 0; i < 4; ++i) {
        fun_ex[i] = fun_in[i] + (1.0 / RELAXATION_TIME) * (fun_eq[i] - fun_in[i]);
     }
}
