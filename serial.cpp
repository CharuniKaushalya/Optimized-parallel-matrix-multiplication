/*
Sequential program to perform matrix-matrix multiplication
*/
#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <cmath>
#include <omp.h>

using namespace std;

void populateMatrix(double ** matrix, int n);
double ** initializeMatrix(int n);
double multiplyMatrix(int n);

// Assign random values to square matrice.
void populateMatrix(double ** matrix, int n){

	for(int i = 0; i < n; i++ ){
		for(int j = 0; j < n; j ++){
			matrix[i][j] = rand();
		}
	}
}

double ** initializeMatrix(int n){
	double ** matrix;
	matrix = new double*[n];;
	for (int row = 0; row<n; row++) {
	  matrix[row] = new double[n];
	}
	return matrix;
}

double multiplyMatrix(int n) {

	//define metrices
	double **matrixA;
	double **matrixB;
	double **matrixC;

	//initialze metrices
	matrixA = initializeMatrix(n);
	matrixB = initializeMatrix(n);
	matrixC = initializeMatrix(n);

	//fill values for metrices randomly
	populateMatrix(matrixA, n);
	populateMatrix(matrixB, n);
        
    double start, end;
	start = omp_get_wtime();  //take the time before multiplication
        
	/*
	*matrix multiplication (sequential)
	*/
	double sum;

	for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            sum = 0.0;
	            for (int k = 0; k < n; k++) {
	            	sum += matrixA[i][k] *  matrixB[k][j];;
	            }
	            matrixC[i][j] =sum;
	        }
	    }
	/*
	*end of matrix multiplication (sequential)
	*/

	end = omp_get_wtime(); //take the time after the multiplication
	double elapsed_time = end -start;

	//delete the matrices
	for (size_t i = 0; i < n; i++) {
        delete [] matrixA[i];
        delete [] matrixB[i];
        delete [] matrixC[i];
    }
	delete[] matrixA;
	delete[] matrixB;
	delete[] matrixC;

	return elapsed_time;
}

int main(int argc, const char * argv[]) {
	int n = atoi(argv[1]);  //getting the input for the matrix size
	double time = multiplyMatrix(n);
	cout << time << endl;
	return 0;
}
