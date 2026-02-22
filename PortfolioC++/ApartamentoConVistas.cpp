#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/*
 * Coste: O(n) (siendo n el número de edificios)
 *
 * Justificación del coste: el coste de la función resolver es lineal siendo n el número de elementos del vector.
 * Esto es así porque se va recorriendo el vector una única vez y todas las operaciones tienen un coste constante.
 *
 *
 * Especificación:
 *
 *      P:{
 *          v.size() >= 0 ^
 *          (Para todo e : 0 <= e < v.size() : v[e].altura >= 0) ^
 *          (Para todo e : 0 <= e < v.size() : -1 <= v[e].piso <= v[e].altura) ^
 *          0 <= i < v.size()
 *      }
 *      tieneVistas(v, i)
 *      Q:{
 *          return true si (Para todo e : i < e < v.size() : v[i].piso > v[e].altura)
 *          return false en caso contrario
 *      }
 *
 *      P:{
 *          v.size() >= 0 ^
 *          (Para todo i : 0 <= i < v.size() : v[i].altura >= 0) ^
 *          (Para todo i : 0 <= i < v.size() : -1 <= v[i].piso <= v[i].altura)
 *      }
 *      vector<int> resolver(vector<tEdificio> & v) return sol
 *      Q:{
 *          0 <= sol.size() <= v.size() ^
 *          (Para todo i : 0 <= i < sol.size() : tieneVistas(sol, i))
 *      }
 *
 *      I: {
 *          -1 <= i <= v.size() - 2 ^
 *          alturaMaxima = (Para todo e : i <= e < v.size() : max(v[e].altura)) ^
 *          (Para todo e : 0 <= e < sol.size() : tieneVistas(sol, e))
 *      }
 *      Función cota: i + 1
 */

struct tEdificio {
    string identificador;
    int altura;
    int piso;
};

vector<int> resolver(vector<tEdificio>& v) {
    vector<int> sol;
    int alturaMaxima = v[v.size() - 1].altura;

    if (v[v.size() - 1].piso >= 0) sol.push_back(v.size() - 1);

    for (int i = v.size() - 2; i >= 0; --i) {
        if (v[i].altura > alturaMaxima) {
            if (v[i].piso > alturaMaxima) sol.push_back(i);

            alturaMaxima = v[i].altura;
        }
    }

    return sol;
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0) return false;

    vector<tEdificio> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].identificador >> v[i].altura >> v[i].piso;
    }
    vector<int> sol = resolver(v);

    if (sol.size() == 0) {
        cout << "Ninguno\n";
    }
    else {
        cout << sol.size() << '\n';
        for (int i = 0; i < sol.size(); ++i) {
            cout << v[sol[i]].identificador << ' ';
        }
        cout << '\n';
    }

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}