#pragma once

#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <iostream>

// Este listado es una estructura, no es lo mas recomendable si ya tienes muchas
// estructuras en tu proyecto. Si puedes, cambialo a un namespace usando
// namespace listado

// Vas a tener que hacer algunas cosas que el compilador diga, y tambien vas a poder
// meterte al arreglo de datos directamente si usas un namespace, pero tu codigo se vera menos atractivo.

struct _listado
{
	// Ingresa una nueva persona a los vectores con los datos.
	void nuevaPersona(std::string nombre, float altura, float peso)
	{
		// Se empujan los nuevos datos a los respectivos vectores.
		nombres.push_back(nombre);
		alturas.push_back(altura);
		pesos.push_back(peso);
	}

	// Si tienes alguna otra manera de obtener los datos, borra esta funcion.
	void obtenerDatos(int people)
	{
		for (int q = 0; q < people; q++)
		{
			std::cout << "\nNombre: ";
			char nameInput[128]{ 0 };
			std::cin.getline(nameInput, 128);

			std::cout << "Altura: ";
			float heightInput = 0;
			std::cin >> heightInput;

			std::cout << "Peso: ";
			float weightInput = 0;
			std::cin >> weightInput;

			nuevaPersona(nameInput, heightInput, weightInput);
			std::cin.ignore();
		}
	}

	// Devuelve la altura promedio.
	float alturaPromedio()
	{
		float retfloat = 0;

		for (int q = 0; q < alturas.size(); q++)
			retfloat += alturas.at(q) / alturas.size();

		return retfloat;
	}

	// Devuelve el peso promedio.
	float pesoPromedio()
	{
		float retfloat = 0;

		for (int q = 0; q < pesos.size(); q++)
			retfloat += pesos.at(q) / pesos.size();

		return retfloat;
	}

	// Devuelve una string para mostrar en pantalla. 
	std::string string()
	{
		std::string retstring = "\n\tNombre\t\tAltura\tPeso\n";

		for (int i = 0; i < pesos.size(); i++)
		{
			std::stringstream sstream;

			sstream << "\t\t" << std::setprecision(3) << alturas.at(i);
			std::string heightString = sstream.str();
			sstream.str("");

			sstream << "\t" << std::setprecision(3) << pesos.at(i);
			std::string weightString = sstream.str();
			sstream.str("");

			retstring += "\t" + (std::string)nombres.at(i) + heightString + weightString + "\n";
		}
		return retstring;
	}

private:
	std::vector<std::string> nombres;
	std::vector<float> pesos, alturas;
};
_listado listado;