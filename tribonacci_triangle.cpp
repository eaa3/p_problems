/********

@author: Ermano Arruda, 2018


Tribonnaci triangle: https://oeis.org/A008288

********/


#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>


const int size = 100;
const int fac_size = 100;

long long table[size][size];
long long factorial[fac_size];

void comp_fac(){

	factorial[0] = 1;
	for(int i = 1; i < fac_size; i++){
		factorial[i] = i*factorial[i-1];
	}

}


long long comb(int i, int k){

	return factorial[i]/(factorial[i-k]*factorial[k]);
}


void tribonacciTriangle(int n){

	n = std::min(size,n);

	table[0][0] = 1; table[0][1] = 0;
	table[1][0] = 1; table[1][1] = 1;
	for(int i = 2; i < size; i++){

		table[i][0] = 1;
		
		for(int j = 1; j < i; j++){

			table[i][j] = table[i-2][j - 1] + table[i-1][j-1] + table[i-1][j];
			
		}

		table[i][i] = 1;

		
	}
}

void print(int n){

	n = std::min(size,n);

	for(int i = 0; i < n; i++){

		for(int j = 0; j < n; j++){

			printf("%lld ",table[i][j]);

		}
		printf("\n");	
		
	}
}


int main(int argc, char **args){

	if( argc < 2 ){
		printf("usage: tribonacci_triangle <n>\n");
		return 0;
	}

	int n = atoi(args[1]);
	tribonacciTriangle(n);
	print(n);





	return 0;
}