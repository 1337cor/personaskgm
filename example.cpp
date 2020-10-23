#include "listado.hpp" // Todas las librerias necesarias estan incluidas en el header.

int main()
{
	int people = 0;

	std::cout	<< "Cuanta gente va a estar en la lista: ";
	std::cin	>> people;
	
	std::cin.ignore();
	
	listado.obtenerDatos(people);

	std::cout << listado.string()

	<< "\nAltura promedio: "	<< listado.alturaPromedio()
	<< "\nPeso promedio: "		<< listado.pesoPromedio()	<< "\n\nPresiona enter para salir";

	std::cin.ignore();
}