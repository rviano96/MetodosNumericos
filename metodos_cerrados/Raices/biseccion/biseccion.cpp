/*
 * Método cerrado - Bisección
 * Dados dos intervalos xl y xu y una funcion f(x), encontrar la raiz
 * que encierra ese intervalo.
 */

#include <iostream>
using namespace std;
#include <math.h>

double funcion(double x){
    return pow(x,10) - 1; // Reemplazar por cualquier funcion
}

int main(){
    // xl,xu -> Intervalos de busqueda [inferior,superior]
    // xr -> Resultado de subdividir los intervalos para re evaluar la funcion achicando el intervalo
    // Cantidad de iteraciones que se estima encontrar la raiz
    // ea -> Error relativo porcentual ; es -> Valor previamente fijado (TODO)
    // xrold -> valor anterior de xr para calcular el error relativo porcentual
    double xl, xu, xr, ea, es, xrold;
    int it;

    cout << "Limite inferior:" << flush;
    cin >> xl;
    cout << "Limite superior:" << flush;
    cin >> xu;
    cout << "Error: " << flush;
    cin >> es;
    cout << "Cantidad de iteraciones:" << flush;
    cin >> it;

    if (funcion(xl) == 0){
        cout << "xl es raiz: " << xl << endl;
        return 0;
    }

    if (funcion(xu) == 0){
        cout << "xu es raiz: " << xu << endl;
        return 0;
    }

    if (funcion(xl) * funcion(xu) > 0){
        cout << "Existe un numero par de raizes " << endl;
        return 0;
    }

    for (int i; i < it; i++){

        xr = (xl + xu) / 2;
        if (funcion(xl) * funcion(xr) < 0){
            xu = xr;
        }else{
            xl = xr;
        }
        if (funcion(xl) * funcion(xr) == 0){
            break;
        }
        ea = fabs((xr - xrold)/xr)*100;
        xrold = xr;

        if(ea < es){
            it = i;
            break;
        }
    }
    cout << "La raiz encontrada entre los intervalos es: " << xr << endl;
    cout << "Cantidad de iteraciones realizadas: " << it << endl;

    return 0;
}