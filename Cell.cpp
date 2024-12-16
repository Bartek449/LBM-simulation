#include"Cell.h"

Cell::Cell() : info(EMPTY) {}

Cell::Cell(array<double,4> i) {info = i;}

void Cell::set_info(array<double,4> i) {info = i; }

const array<double,4>& Cell::get_info() const { return info; }

double Cell::calculate_density()
{
    double p = 0.0;
    for (const auto& val : info)
    {
        p += val;
    }
    return p;
}

double Cell::calculate_fun_eq() { return calculate_density() / info.size(); }

array < double,4> Cell::calculate_fun_exit() 
{ 
    array <double, 4> f_ex;
    double f_eq = calculate_fun_eq();
    for (int i = 0; i < 4; ++i) {
        f_ex[i] = info[i] + (1.0 / RELAVATION_TIME) * (f_eq - info[i]); 
     }

        return f_ex;
}
