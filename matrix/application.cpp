#include "application.h"

void Application::print_menu(Matrix& matrix)
{
	int user;
	do
	{
		system("cls");

		cout << "Матрица A:" << endl;
		cout << matrix << endl;

		cout << "Выбирите действие:" << endl
			<< "[1] Сложение;" << endl
			<< "[2] Умножение;" << endl
			<< "[3] Транспонирование;" << endl
			<< "[4] Просмотреть элемент;" << endl
			<< "[5] Установить элемент;" << endl
			<< "[0] Выход" << endl
			<< "-> ";
		cin >> user;

		system("cls");

		switch (user)
		{
			case 1:
				matrix = amount(matrix);
				break;

			case 2:
				matrix = mult(matrix);
				break;

			case 3:
				matrix.transpose();
				break;

			case 4:
				print_element(matrix);
				break;

			case 5:
				change_element(matrix);
				break;
		}
	} while (user != 0);
}

Matrix Application::amount(Matrix& A)
{
	cout << "Заполните матрицу B" << endl;
	system("pause");

	Matrix B(A.get_rows(), A.get_cols());
	cin >> B;
	return A + B;
}

Matrix Application::mult(Matrix& A)
{
	int cols;
	cout << "Матрица B:" << endl
		<< "Количество колонок" << endl
		<< "-> ";
	cin >> cols;

	Matrix B(A.get_cols(), cols);
	cin >> B;

	return A * B;
}

void Application::print_element(Matrix& matrix)
{
	cout << matrix << endl;

	cout << matrix(enter_col(), enter_row()) << endl;
	system("pause");
}

void Application::change_element(Matrix& matrix)
{
	cout << matrix << endl;

	matrix.set_element(enter_item(), enter_col(), enter_row());
}

int Application::enter_row()
{
	int row;

	cout << "Номер строки:" << endl
		<< "-> ";
	cin >> row;

	return --row;
}

int Application::enter_col()
{
	int col;

	cout << "Номер колонки:" << endl
		<< "-> ";
	cin >> col;

	return --col;
}

int Application::enter_item()
{
	int item;

	cout << "Новое значение элемента" << endl
		<< "-> ";
	cin >> item;

	return item;
}

void Application::set_parameters(Matrix& matrix)
{
	int rows, cols;
	cout << "Введите количество строк -> ";
	cin >> rows;
	cout << "Введите количество колонок -> ";
	cin >> cols;

	matrix.set_rows(rows);
	matrix.set_cols(cols);
}

void Application::start()
{
	Matrix A;
	set_parameters(A);
	cin >> A;
	print_menu(A);
}
