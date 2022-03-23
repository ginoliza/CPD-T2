#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

#define n 4096

int A[n][n];
int B[n][n];
int C[n][n];

int main() {	
	int b = 6;
	
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

	for (int i0 = 0; i0 < n; i0 = i0 + b)
	for (int j0 = 0; j0 < n; j0 = j0 + b)
	for (int z0 = 0; z0 < n; z0 = z0 + b)
	for (int i = i0; i < min(i0 + b, n); ++i)
	for (int j = j0; j < min(j0 + b, n); ++j)
	for (int z = z0; z < min(z0 + b, n); ++z){
		C[i][j] = C[i][j] + A[i][z] * B[z][j];	
	}

	//tomar tiempo final
	auto fin = std::chrono::high_resolution_clock::now();

	//imprimir total = final - inicial
	double total = std::chrono::duration<double, std::milli>(fin - inicio).count();
	cout << "Multiplicacion clasica: " << total << "\n";

	/*
	cout<<"Matriz A: "<<endl;
	for(int i=0; i<n; ++i){
	   for(int j=0; j<n; ++j){
		   cout<<A[i][j]<<" ";
	   }
	   cout<<endl;
	}
   
	cout<<"Matriz B: "<<endl;
   for(int i=0; i<n; ++i){
	   for(int j=0; j<n; ++j){
		   cout<<B[i][j]<<" ";
	   }
	   cout<<endl;
   }
   cout<<"Matriz C: "<<endl;
   for(int i=0; i<n; ++i){
	   for(int j=0; j<n; ++j){
		   cout<<C[i][j]<<" ";
	   }
	   cout<<endl;
   }
 */


	return 0;
}
