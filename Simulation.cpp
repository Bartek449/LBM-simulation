#include "Simulation.h"

Simulation::Simulation(int rows, int columns) : s(rows, columns) {}

Matrix& Simulation::get_matrix() { return s; }

void Simulation::collision() {
    Matrix next_matrix = s;
    int rows = s.get_rows_num();
    int columns = s.get_columns_num();
    vector<int> left_right{ 1, 0, 1, 0 };
    vector<int> up_down{ 0, 1, 0, 1 };

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            const array<double,4>& fun_in = s.get_element(i, j).get_fun(FUN_IN);
            Cell& future_cell = next_matrix.get_element(i, j);

            

           

        }
    }

    s = next_matrix;
}


void Simulation::streaming() {
    Matrix next_matrix = s;
    int rows = s.get_rows_num();
    int columns = s.get_columns_num();

    for (size_t i = 1; i < rows - 1; i++) {
        for (size_t j = 1; j < columns - 1; j++) {
            Cell& current_cell = s.get_element(i, j);
            array<double, 4> fun_ex = current_cell.get_fun(FUN_EX);

            if (fun_ex[0]) {
                Cell& right_cell = s.get_element(i, j + 1);
                if (right_cell.get_fun(FUN_IN) == WALL) {
                    next_matrix.get_element(i, j).set_direct_fun(FUN_IN, 2, fun_ex[0]);
                }
                else {
                    next_matrix.get_element(i, j + 1).set_direct_fun(FUN_IN,0, fun_ex[0]);
                }
            }
            if (fun_ex[1]) {
                Cell& down_cell = s.get_element(i + 1, j);
                if (down_cell.get_fun(FUN_IN) == WALL) {
                    next_matrix.get_element(i, j).set_direct_fun(FUN_IN, 3, fun_ex[1]);
                }
                else {
                    next_matrix.get_element(i + 1, j).set_direct_fun(FUN_IN, 1, fun_ex[1]);
                }
            }
            if (fun_ex[2]) {
                Cell& left_cell = s.get_element(i, j - 1);
                if (left_cell.get_fun(FUN_IN) == WALL) {
                    next_matrix.get_element(i, j).set_direct_fun(FUN_IN, 0, fun_ex[2]);
                }
                else {
                    next_matrix.get_element(i, j - 1).set_direct_fun(FUN_IN, 2, fun_ex[2]);
                }
            }
            if (fun_ex[3]) {
                Cell& up_cell = s.get_element(i - 1, j);
                if (up_cell.get_fun(FUN_IN) == WALL) {
                    next_matrix.get_element(i, j).set_direct_fun(FUN_IN, 1, fun_ex[3]);
                }
                else {
                    next_matrix.get_element(i - 1, j).set_direct_fun(FUN_IN, 3, fun_ex[3]);
                }
            }
        }
    }

    for (size_t i = 1; i < rows - 1; i++) {
        for (size_t j = 1; j < columns - 1; j++) {
            Cell& next_cell = next_matrix.get_element(i, j);
            if (s.get_element(i, j).get_fun(FUN_IN) != WALL) {
                next_cell.calculate_density();
                next_cell.calculate_fun_eq();
                next_cell.calculate_fun_ex();
            }
        }
    }


    s = next_matrix;
}