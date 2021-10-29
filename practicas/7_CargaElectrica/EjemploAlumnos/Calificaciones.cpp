#include <iostream>
#include <array>
#include <string>

#include "Alumno.h"

using namespace std;

Alumno CrearAlumno(int i, string materia);

template <typename alumnos>
float CalificacionPromedio(alumnos todosAlumnos);

int main ()
{
  const int numAlumnos = 3;
  string nombreMateria;
  array <Alumno, numAlumnos> todosAlumnos;

  cout << "Nombre de la materia: ";
  cin >> nombreMateria;

  for (int i = 0; i < numAlumnos; i++)
    todosAlumnos[i] = CrearAlumno(i, nombreMateria);

  cout << "La califiacion promedio en " << nombreMateria << " es de: " << CalificacionPromedio(todosAlumnos) << endl;

  return 0;
}

Alumno CrearAlumno(int i, string materia)
{
  string nombre;
  float calificacion;

  cout << "Nombre del alumno " << i << ": ";
  cin >> nombre;
  cout << "Calificacion en " << materia << ": ";
  cin >> calificacion;
  Alumno miAlumno(nombre, calificacion);
  return miAlumno;
}

template <typename alumnos>
float CalificacionPromedio(alumnos todosAlumnos)
{
  int numAlumnos = todosAlumnos.size();
  float calificacion = 0;
  for (int i = 0; i < numAlumnos; i++)
    calificacion += todosAlumnos[i].GetCalificacion();
  return calificacion / numAlumnos;
}
