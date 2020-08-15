#include <Windows.h>
#include"application.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Application application;
	application.start();

	return 0;
}