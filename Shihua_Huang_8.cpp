// Repeated Squaring Algorithm
//
#define _CRT_SECURE_NO_WARNINGS
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <complex>
#include "newmat.h"
#include "newmatap.h"
#include "Shihua_Huang_8.h"

using namespace std;

int main(int argc, char* argv[])
{
	int no_of_rows, exponent;

	//part 1: calculate time it took with 2 different methods
	sscanf(argv[1], "%d", &no_of_rows);//number of rows in a matrix for calculation
	sscanf(argv[2], "%d", &exponent);//exponent for calculation

	cout << "The number of rows/columns in the square matrix is: " << no_of_rows << endl;
	cout << "The exponent is " << exponent << endl;

	Matrix A(no_of_rows, no_of_rows);
	srand((unsigned)time(NULL));
	create_random_matrix(A, no_of_rows);

	cout << "Repeated Squaring Result:" << endl;
	cout << "It took " << calculate_time_repeated_squaring(A, exponent, no_of_rows) << " seconds to complete" << endl;

	cout << "Direct Multiplication Result:" << endl;
	cout << "It took " << calculate_time_direct_multiplication(A, exponent, no_of_rows) << " seconds to complete" << endl;

	//part2: derive data of computation time as a function of matrix size and exponent
	write_data_a_function_of_size("computation_time_size.txt");
	cout << "Set fixed exponent at 30 and compute time of 2 methods as a function of size from 1 to 300 " << endl;
	
	write_data_a_function_of_exponent("computation_time_exponent.txt");
	cout << "Set fixed size at 5 and compute time of 2 methods as a function of exponent from 1 to 300" << endl;
}

   