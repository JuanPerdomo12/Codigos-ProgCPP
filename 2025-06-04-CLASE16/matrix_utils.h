#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <random>

void print_matrix(const std::vector<double> & M, int nrows, int ncols);
void fill_matrix_random(std::vector<double> & M, const int nrows, const int ncols, const int seed);
double trace_matrix(const std::vector<double> & M, int nrows, int ncols);
void fill_matrix(std::vector<double> & data, int m, int n);
void matrix_matrix_multi(const std::vector<double> & M1, const std::vector<double> & M2, 
            std::vector<double> & MM, int M1rows, int M1cols, int M2rows, int M2cols);
void identity_matrix( std::vector<double> & I, int nrows);
bool check_inverse(const std::vector<double> & A, const std::vector<double> & B, const std::vector<double> &I_n, double epsilon, int n);
