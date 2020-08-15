#pragma once
#include"matrix.h"

class Application
{
private:
	void print_menu(Matrix& matrix);
	Matrix amount(Matrix& A);
	Matrix mult(Matrix& A);
	void print_element(Matrix& matrix);
	void change_element(Matrix& matrix);

	int enter_row();
	int enter_col();
	int enter_item();

	void set_parameters(Matrix& matrix);

public:
	void start();
};