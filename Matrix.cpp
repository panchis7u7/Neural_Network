#include "Matrix.h"

// Uploaded by panchis7u7 ~ Sebastian Madrigal

Matrix::Matrix(int filas, int columnas) {
	this->filas = filas;
	this->columnas = columnas;
	this->datos = new float* [this->filas];
	for (size_t i = 0; i < this->filas; i++)
	{
		this->datos[i] = new float[this->columnas];
	}
}

Matrix::Matrix() {
	this->datos = alloc(0,0);
}

Matrix::~Matrix() {
	for (size_t i = 0; i < this->filas; i++)
	{
		delete[] datos[i];
	}
	delete[] datos;
	std::cout << "Se borro la matriz!" << std::endl;
}

float** Matrix::alloc(int filas, int columnas) {
	this->filas = filas;
	this->columnas = columnas;
	float** datos = new float* [this->filas];
	for (size_t i = 0; i < this->filas; i++)
	{
		datos[i] = new float[this->columnas];
	}
	return datos;
}

void Matrix::print() {
	for (size_t i = 0; i < filas; i++)
	{
		std::cout << "|";
		for (size_t j = 0; j < columnas; j++)
		{
			std::cout << "  " << datos[i][j] << "  ";
		}
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Matrix::suma(int n) {
	for (size_t i = 0; i < this->filas; i++)
	{
		for (size_t j = 0; j < this->columnas; j++)
		{
			this->datos[i][j] += n;
			datos[i][j] += n;
		}
	}
}

void Matrix::aleatorizar() {
    float x;
	srand(time(0));
	for (size_t i = 0; i < this->filas; i++)
	{
		for (size_t j = 0; j < this->columnas; j++)
		{
			x = (float(rand())/float((RAND_MAX)) * 2) - 1; //Genera numero aleatorio entre -1 y 1
			this->datos[i][j] = x;
		}
	}
}

Matrix* Matrix::transpuesta() {
	Matrix* resultado = new Matrix(this->columnas, this->filas);
	for (size_t i = 0; i < this->filas; i++)
	{
		for (size_t j = 0; j < this->columnas; j++)
		{
			resultado->datos[j][i] = this->datos[i][j];
		}
	}
	return resultado;
}

void Matrix::sumar(Matrix* sumando) {
	for (size_t i = 0; i < this->filas; i++)
	{
		for (size_t j = 0; j < this-> columnas; j++)
		{
			this->datos[i][j] += sumando->datos[i][j];
		}
	}
}

void Matrix::map(float (*func)(float)) {
	for (size_t i = 0; i < this->filas; i++)
	{
		for (size_t j = 0; j < this->columnas; j++)
		{
			this->datos[i][j] = func(this->datos[i][j]);
		}
	}
}