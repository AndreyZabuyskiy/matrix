#include "application.h"

void Application::print_menu(Matrix& matrix)
{
	int user;
	do
	{
		system("cls");

		cout << "������� A:" << endl;
		cout << matrix << endl;

		cout << "�������� ��������:" << endl
			<< "[1] ��������;" << endl
			<< "[2] ���������;" << endl
			<< "[3] ����������������;" << endl
			<< "[4] ����������� �������;" << endl
			<< "[5] ���������� �������;" << endl
			<< "[0] �����" << endl
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
	cout << "��������� ������� B" << endl;
	system("pause");

	Matrix B(A.get_rows(), A.get_cols());
	cin >> B;
	return A + B;
}

Matrix Application::mult(Matrix& A)
{
	int cols;
	cout << "������� B:" << endl
		<< "���������� �������" << endl
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

	cout << "����� ������:" << endl
		<< "-> ";
	cin >> row;

	return --row;
}

int Application::enter_col()
{
	int col;

	cout << "����� �������:" << endl
		<< "-> ";
	cin >> col;

	return --col;
}

int Application::enter_item()
{
	int item;

	cout << "����� �������� ��������" << endl
		<< "-> ";
	cin >> item;

	return item;
}

void Application::set_parameters(Matrix& matrix)
{
	int rows, cols;
	cout << "������� ���������� ����� -> ";
	cin >> rows;
	cout << "������� ���������� ������� -> ";
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
