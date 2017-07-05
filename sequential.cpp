/*
Sequential program to perform matrix-matrix multiplication
*/
#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <cmath>
#include <omp.h>


using namespace std;

double matrixA[1000][1000];
double matrixB[1000][1000];
double matrixC[1000][1000];

void populateMatrix(int n);
void multiplyMatrix(int n);
void transpose(int n);

int main(int argc, char** argv){
	int n = atoi(argv[1]);  //getting the input for the matrix size
	populateMatrix(n);

	double start, end;
	start = omp_get_wtime();  //take the time before multiplication
	multiplyMatrix(n);
	end = omp_get_wtime(); //take the time after the multiplication

	double elapsed_time = end -start;
	
	cout << endl << "Time for Multiplication: " << elapsed_time << endl;
	
	return 0;
}

// Initialize the two square matrices.
void populateMatrix(int n){
	
	for (int i=0; i<n; i++){		
		for (int j=0; j<n; j++){
			matrixA[i][j] = rand();
			matrixB[i][j] = rand();
		}
	}
}

// Computes the product of two square matrices.
void multiplyMatrix(int n){
	
	 for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k)
            {
                matrixC[i][j] += matrixA[i][k] *  matrixB[k][j];
            }
		}
	}
}




