#include"Cell.h"

Cell::Cell() : fun_in(EMPTY) {}

Cell::Cell(array<double,4> i) { fun_in = i;}

void Cell::set_fun_in(array<double,4> i) { fun_in = i; }

void Cell::set_direct_fun_in(int index, double num) {
    fun_in[index] = num;
}

const array<double,4>& Cell::get_fun_in() const { return fun_in; }

double Cell::calculate_density()
{
    double p = 0.0;
    for (const auto& val : fun_in)
    {
        p += val;
    }
    return p;
}

double Cell::calculate_fun_eq() { return calculate_density() / fun_in.size(); }

array < double,4> Cell::calculate_fun_ex() 
{ 
    array <double, 4> f_ex;
    double f_eq = calculate_fun_eq();
    for (int i = 0; i < 4; ++i) {
        f_ex[i] = fun_in[i] + (1.0 / RELAVATION_TIME) * (f_eq - fun_in[i]);
     }

     return f_ex;
}
