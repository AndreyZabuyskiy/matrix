#include "matrix.h"

// Перегрузка конструкторов

Matrix::Matrix(): rows(0), cols(0), field(nullptr){}

Matrix::Matrix(int rows, int cols): rows(rows), cols(cols)
{
	initialization();
}

// Перегрузка операторов

Matrix Matrix::operator+(Matrix& other)
{
	Matrix tmp(this->rows, this->cols);
	int tmp_element;

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			tmp_element = field[i][j] + other(i, j);
			tmp.set_element(tmp_element, j, i);
		}
	}

	return tmp;
}

Matrix Matrix::operator*(Matrix& other)
{
	Matrix tmp(other.get_rows(), other.get_cols());

	int tmp_element = 0;

	for (int i = 0; i < other.get_rows(); ++i)
	{
		for (int j = 0; j < other.get_cols(); ++j)
		{
			for (int k = 0; k < other.get_rows(); ++k)
			{
				tmp_element += field[i][k] * other.get_field()[k][j];
			}

			tmp.set_element(tmp_element, j, i);
			tmp_element = 0;
		}
	}

	return tmp;
}

Matrix& Matrix::operator=(Matrix other)
{
	remove();

	this->rows = other.get_rows();
	this->cols = other.get_cols();

	initialization();

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			field[i][j] = other.get_field()[i][j];
		}
	}

	return *this;
}

int Matrix::operator()(int col, int row)
{
	return field[row][col];
}

// Геттеры и сеттерры

int Matrix::get_rows()
{
	return rows;
}

int Matrix::get_cols()
{
	return cols;
}

int** Matrix::get_field()
{
	return field;
}

void Matrix::set_rows(int rows)
{
	this->rows = rows;
}

void Matrix::set_cols(int cols)
{
	this->cols = cols;
}

// public функции

Matrix& Matrix::transpose()
{
	Matrix tmp(this->cols, this->rows);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			tmp.get_field()[j][i] = field[i][j];
		}
	}

	*this = tmp;
	return *this;
}

void Matrix::set_element(int item, int col, int row)
{
	field[row][col] = item;
}

//Matrix::~Matrix()
//{
//	if (field != nullptr)
//	{
//		for (int i = 0; i < rows; ++i)
//		{
//			delete[] field[i];
//		}
//		delete[] field;
//	}
//}

// private функции

void Matrix::initialization()
{
	field = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		field[i] = new int[cols];
	}
}

void Matrix::remove()
{
	if (field != nullptr)
	{
		for (int i = 0; i < rows; ++i)
		{
			delete[] field[i];
		}
		delete[] field;
	}
}

void Matrix::fill_zero()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			field[i][j] = 0;
		}
	}
}

// friend функции

ostream& operator << (ostream& os, const Matrix& matrix)
{
	for (int i = 0; i < matrix.rows; ++i)
	{
		for (int j = 0; j < matrix.cols; ++j)
		{
			os << "[" << matrix.field[i][j] << "] ";
		}
		os << endl;
	}
	return os;
}

istream& operator >> (istream& is, Matrix& matrix)
{
	matrix.remove();
	matrix.initialization();
	
	matrix.fill_zero();

	for (int i = 0; i < matrix.rows; ++i)
	{
		for (int j = 0; j < matrix.cols; ++j)
		{
			system("cls");

			cout << matrix << endl;
			cout << "[" << i + 1 << "][" << j + 1 << "] -> ";
			is >> matrix.field[i][j];
		}
	}

	return is;
}
