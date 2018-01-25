// Repeated Squaring Algorithm
//
#include <cmath>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <chrono>
#include "newmat.h"
#include "newmatap.h"

using namespace std; 

double get_uniform()
{
	return((double)rand() / RAND_MAX);
}

// This routine fills a n x n matrix, with random entries
void create_random_matrix(Matrix &A, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			A.element(i, j) = 10.0*get_uniform() - 5;
}

//Multiplying A using repeated squaring algorithm
Matrix repeated_squaring(Matrix A, int exponent, int no_of_rows)
{
	if (exponent == 0) 
	{
		IdentityMatrix I(no_of_rows);
		return (I);
	}
	else if (exponent % 2 == 0)
		return (repeated_squaring(A*A, exponent / 2, no_of_rows));
	else
		return (A*repeated_squaring(A*A, (exponent - 1) / 2, no_of_rows));
}

//Multiplying A with itself k times
Matrix direct_multiplication(Matrix A, int exponent, int no_of_rows)
{
	Matrix C(no_of_rows, no_of_rows);
	C = 1.0;
	C = A;
	for (int i = 1; i < exponent; i++)
	{
		C = A * C;
	}
	return C;
}

//Using chrono to calculate time of repeated squaring algorithm
//Clock() give me really vague output
double calculate_time_repeated_squaring(Matrix A, int exponent, int no_of_rows)
{
	Matrix B(no_of_rows, no_of_rows);
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> elapsed_time;

	start = std::chrono::system_clock::now();//start calculating the time

	B = repeated_squaring(A, exponent, no_of_rows);

	end = std::chrono::system_clock::now();//stop calculating the time
	elapsed_time = end - start;//calculate the time used

	return elapsed_time.count();

	/*Matrix B(no_of_rows, no_of_rows);
	time_before = clock();
	B = repeated_squaring(A, exponent, no_of_rows);
	time_after = clock();
	diff1 = (time_after - time_before) / CLOCKS_PER_SEC;
	return diff1;*/
}

//Using chrono to calculate time of direct multiplication
//Clock() give me really vague output
double calculate_time_direct_multiplication(Matrix A, int exponent, int no_of_rows)
{
	Matrix D(no_of_rows, no_of_rows);
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> elapsed_time;

	start = std::chrono::system_clock::now();//start calculating the time

	D = direct_multiplication(A, exponent, no_of_rows);

	end = std::chrono::system_clock::now();//stop calculating the time
	elapsed_time = end - start;//calculate the time used

	return elapsed_time.count();

	/*Matrix D(no_of_rows, no_of_rows);
	time_before = clock();
	D = direct_multiplication(A, exponent, no_of_rows);
	time_after = clock();
	diff2 = (time_after - time_before) / CLOCKS_PER_SEC;
	return diff2;*/
}

//Let matirx size from 1 to 300, set exponent fixed at 30, output data
void write_data_a_function_of_size(char*filename)
{
	ofstream out_filename(filename);
	if (out_filename.is_open())
	{
		for (int i = 1; i <= 300; i++)
		{
			Matrix F(i, i);
			srand((unsigned)time(NULL));
			create_random_matrix(F, i);

			double diff3 = calculate_time_repeated_squaring(F, 30, i);
			double diff4 = calculate_time_direct_multiplication(F, 30, i);
			out_filename << i << "  " << diff3 << "  " << diff4 << endl;
		}
		out_filename.close();
	}
}

//Let exponent from 1 to 300, set matrix size fixed at 5, output data
void write_data_a_function_of_exponent(char*filename)
{
	ofstream out_filename(filename);
	if (out_filename.is_open())
	{
		for (int i = 1; i <= 300; i++)
		{
			Matrix F(5, 5);
			srand((unsigned)time(NULL));
			create_random_matrix(F, 5);

			double diff3 = calculate_time_repeated_squaring(F, i, 5);
			double diff4 = calculate_time_direct_multiplication(F, i, 5);
			out_filename << i << "  " << diff3 << "  " << diff4 << endl;
		}
		out_filename.close();
	}
}


