#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <random>
void print_matrix(const std::vector<double> & M, int nrows, int ncols);
void fill_matrix_random(std::vector<double> & M, const int nrows, const int ncols, const int seed);
double trace_matrix(const std::vector<double> & M, int nrows, int ncols);
