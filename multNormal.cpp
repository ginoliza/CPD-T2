#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

#define n 2048

int main()
{
	vector<vector<float>> A, B;
	//llenar
	for (int i = 0; i < n; ++i) {
		A.push_back(vector<float>());
		B.push_back(vector<float>());
		for (int j = 0; j < n; ++j) {
			A[i].push_back((float)rand() / (float)RAND_MAX);
			B[i].push_back((float)rand() / (float)RAND_MAX);
		}
	}

	cout << "Ejecutando multiplicacion de matrices clasica...\n";
	auto started = chrono::high_resolution_clock::now();

	vector<vector<float>> C(n, vector<float>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}	

	auto done = chrono::high_resolution_clock::now();
	cout << "Tiempo de ejecucion (ms): " << chrono::duration_cast<chrono::milliseconds>(done - started).count() << "\n\n";

	return 0;
}
