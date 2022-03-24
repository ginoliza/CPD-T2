#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#include <chrono>

using namespace std;

#define n 2048

int main()
{
	vector<vector<float>> A, B;
	// llenar
	for (int i = 0; i < n; ++i) {
		A.push_back(vector<float>());
		B.push_back(vector<float>());
		for (int j = 0; j < n; ++j) {
			A[i].push_back((float)rand() / (float)RAND_MAX);
			B[i].push_back((float)rand() / (float)RAND_MAX);
		}
	}	
	
	// iteramos a traves de distintos exponentes para calcular el tamaño del bloque
	//for (int EX = 1; EX < 8; EX++) {

		//cout << "Exponente: " << EX << endl;
		auto started = chrono::high_resolution_clock::now();

		int cantBloq = pow(2, EX); // cuántos bloques queremos 	[1]
		//int cantBloq = n/32; // cuántos bloques queremos			[2]
		//int cantBloq = 2;//											[3]
		int b = n / cantBloq; // tamaño del bloque
		vector<vector<float>> C(n, vector<float>(n, 0));

		for (int ii = 1; ii <= cantBloq; ii++) {
			for (int jj = 1; jj <= cantBloq; jj++) {
				for (int kk = 1; kk <= cantBloq; kk++) {
					for (int i = (ii - 1) * b; i < ii * b; ++i) {
						for (int j = (jj - 1) * b; j < jj * b; ++j) {
							for (int k = (kk - 1) * b; k < kk * b; ++k) {
								C[i][j] += A[i][k] * B[k][j];
							}
						}
					}
				}

			}
		}

		auto done = chrono::high_resolution_clock::now();
		cout << chrono::duration_cast<chrono::milliseconds>(done - started).count() << "\n\n";
	//}

	return 0;
}
