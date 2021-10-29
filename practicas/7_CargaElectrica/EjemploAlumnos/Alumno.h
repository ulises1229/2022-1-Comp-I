#ifndef CALIFICACIONES_ALUMNO_H
#define CALIFICACIONES_ALUMNO_H

#include <string>

using namespace std;

class Alumno
{
private:
  string nombre;
  float calificacion;
public:
	Alumno() { nombre = ""; calificacion = 0; };
	Alumno(string nom, float cal) { nombre = nom; calificacion = cal; }
	float GetCalificacion();
};

#endif // !CALIFICACIONES_ALUMNO_H
