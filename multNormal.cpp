#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <chrono>

using namespace std;

#define n 256

int A[n][n];
int B[n][n];
int C[n][n];

int main() {

    //llenar 
    srand(NULL);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
			B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
    }
        
    //tomar tiempo inicial
    auto inicio = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    //tomar tiempo final
    auto fin = std::chrono::high_resolution_clock::now();
    
    //imprimir total = final - inicial
    double total = std::chrono::duration<double, std::milli>(fin - inicio).count();
    cout << "Multiplicacion clasica: " << total << "\n";

    return 0;
}
