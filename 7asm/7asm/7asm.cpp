// 7asm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "");
	int a, b, c, result, i = 0;
	std::cout << "Введите 3 числа: ";
	std::cin >> a >> b >> c;

	_asm {
		mov eax, a
		mov ebx, b

		cikl : cmp eax, ebx
			   je end
			   jg metka
			   sub ebx, eax
			   jmp cikl

		metka : sub eax, ebx
			   jmp cikl

		end : mov result, eax
	}

	i++;

	if (i == 1) {
		printf("%d\n", result);
		printf("НОД двух чисел: %d\n", result);
		int z = result;

		_asm {
			mov eax, c
			mov ebx, z

			jmp cikl
		}

	}
	else
		if (i == 2)
			printf("НОД для трех чисел: %d\n", result);
		else
			printf("3 бит справа - %d\n", result);

	printf("\nВведите 0 для прекращения ввода\n");
	printf("Введите число для проверки 3 разряда справа: ");
	int t;
	std::cin >> t;
	if (t != 0) {
		__asm {
			mov eax, t

			shr eax, 11b
			jnb zer
			jb one

			zer : mov eax, 0
				  jmp end

			one : mov eax, 1
				  jmp end
		}
	}
	return 0;
}