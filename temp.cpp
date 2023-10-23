#include <iostream>
#include <math.h>
#include <sys/time.h>
using namespace std;

int** generateMatrix(int size){ 
    int **matrix = new int*[size];
    for(int i = 0; i < size; i++){
        matrix[i] = new int[size];
        for(int j = 0; j < size; j++)
            matrix[i][j] = rand() % 10;  
    }
    return matrix; 
}

int** multiplyTwoMatrix(int **matrixA, int **matrixB, int size){
    int **res = new int*[size]; 
    for(int i = 0; i < size; i++){
        res[i] = new int[size]; 
        for(int j = 0; j < size; j++) {
            res[i][j] = 0;
            for(int k = 0; k < size; k++) {
                res[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return res; 
}

int main(){
    clock_t start, end;
    double run_time[5];  

    for(int i = 0; i < 5; i++){
        int exponent = i;
        int base = 10; 
        int size = pow(base, i);

        int **matrix = generateMatrix(size); 

        start = clock();
        int **res = multiplyTwoMatrix(matrix, matrix, size);
        end = clock(); 
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        run_time[i] = time_taken; 

        cout << "Matrix size 10^" << i << " take: " << time_taken << " (s)" << endl; 
        for(int j = 0; j < size; j++){
            delete []res[j];
            delete []matrix[j];
        }
        delete []matrix;
        delete []res; 
    }

    return 0; 
}