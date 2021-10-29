#include <iostream>
#include <array>
#include <string>

// Incluimos nuestra clase Grupo
#include "Grupo.h"

using namespace std;

// Declaración de funciones
void PedirpH(float& ph);
Grupo CrearGrupo(int numGrupo);

template <typename grupos>
int CalcularCargaApH(float& ph, grupos todosGrupos);


int main()
{
    // Indicamos el número de grupos que va a tener nuestra molécula
    const int numGrupos = 3;
    float phMolecula; // pH al que va a estar sometida la molécula
    string nombreMolecula;

    // Pedimos al usuario el nombre de la molécula
    cout << "Nombre de la molecula: ";
    cin >> nombreMolecula;

    // Creamos un arreglo de 'Grupos' para los grupos de la molécula
    array <Grupo, numGrupos> todosGrupos;
    // Pedimos información de cada grupo al usuario
    for (int i = 0; i < numGrupos; i++)
        todosGrupos[i] = CrearGrupo(i);

    // Pedimos al usuario indicar el pH al que está la molécula
    PedirpH(phMolecula);

    // Calculamos la carga neta de la molécula a un cierto pH
    int cargaMolecula = CalcularCargaApH(phMolecula, todosGrupos);
    cout << "Carga neta de la molecula: " << cargaMolecula << endl;

    // Si terminamos correctamente la ejecución del programa, regresamos 0
    return 0;
}

// Crea un nuevo 'Grupo' con la información ingresada por el usuario
Grupo CrearGrupo(int i)
{
    string nombreGrupo;
    float pkGrupo;
    int cargaGrupo;
    cout << "Nombre grupo " << i << ": ";
    cin >> nombreGrupo;
    cout << "pK del grupo " << nombreGrupo << ": ";
    cin >> pkGrupo;
    cout << "Carga del grupo " << nombreGrupo << " a pH mayor a " << pkGrupo << ": ";
    cin >> cargaGrupo;
    Grupo miGrupo(nombreGrupo, pkGrupo, cargaGrupo);
    return miGrupo;
}

// Solicita al usuario el valor de pH
void PedirpH(float& ph)
{
    cout << "pH de la solucion (buffer): ";
    cin >> ph;
}

/* Calcula y regresa la carga eléctrica de la molécula dependiendo de la
 * carga eléctrica de cada uno de sus grupos a un cierto pH.
*/
template <typename grupos>
int CalcularCargaApH(float& ph, grupos todosGrupos)
{
    //TODO
}
