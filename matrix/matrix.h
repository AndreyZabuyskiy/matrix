#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class Matrix
{
private:
	int rows = 0;
	int cols = 0;
	int** field;

	void initialization();
	void remove();
	void fill_zero();

public:
	Matrix();
	Matrix(int rows, int cols);

	Matrix operator + (Matrix& other);
	Matrix operator * (Matrix& other);
	Matrix& operator = (Matrix other);
	// При вызове в классе Application в аргументы передаються функции enter_row(), enter_col() 
	// которые вызываются справа налево
	int operator() (int col, int row);

	int get_rows();
	int get_cols();
	int** get_field();

	void set_rows(int rows);
	void set_cols(int cols);

	Matrix& transpose();
	void set_element(int item, int col, int row);

	friend ostream& operator << (ostream& os, const Matrix& matrix);
	friend istream& operator >> (istream& is, Matrix& matrix);

	// В перегрузке оператора присваивания перед return вызываеться деструктор
	// По этой причине деструктор закоментрировал 
	//~Matrix();
};