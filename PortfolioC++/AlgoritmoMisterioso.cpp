#include <iostream>

using namespace std;

const int TMAX = 1000000;  // No habr� vectores de m�s de un mill�n de elementos


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.

	P={n<=TMAX && n>=0 && (para todo i,j:0<=i<=j<=n:v[i]<=v[j])}


*/


int misterio(const int a[], int n) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */

    
	int valor = a[0];
	int max_repetido = a[0];
	int num_repeticiones = 1;
	int max_repeticiones = 1;

	for (int i = 1; i < n; i++) {


		if (a[i] == valor) {


			num_repeticiones++;

			if (num_repeticiones > max_repeticiones || (num_repeticiones == max_repeticiones && a[i] < max_repetido)) {
				max_repeticiones = num_repeticiones;
				max_repetido = a[i];


			}


		}


		if (a[i] != valor) {

			valor = a[i];
			num_repeticiones = 1;


		}



	}



	return max_repetido;
}

/* COMPLEJIDAD:
   -- Determina justificadamente el orden de complejidad en el peor caso
   -- de este algoritmo, indicando claramente cu�l es el tama�o del problema
	  El algoritmo en el peor de los casos todas las instrucciones a excepcion del bucle tienen coste constante , y como
      el bucle da n vueltas en el peor de los casos este algoritmo tiene coste en O(n)


*/


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA. NO MODIFICAR */

void lee_vector(int a[], int& n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int main() {
	static int a[TMAX];
	int n;
	do {
		lee_vector(a, n);
		if (n >= 0) {
			cout << misterio(a, n) << endl;
		}
	} while (n != -1);
}