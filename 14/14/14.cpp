// 14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>

using namespace std;

//2. Позв добав справа новый эл. в массив (HeapReAlloc ++)
//3. Позв удал из массива эл. справа (--)
//4. Позв встав эл. в массив внутрь со сдвигом на 1 эл вправо (++)
//5. Позв удал из массива 1 эл внутри со сдвигом прав. части влево (--)


int main()
{
	setlocale(NULL, "rus");
	int array_of_ints[] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(array_of_ints);
	int* arr = NULL;

	//1. Созд дин.кучу с р-ром = нач.р-р массива целых чисел

	HANDLE h = HeapCreate(HEAP_NO_SERIALIZE, size, size);
	arr = (int*)HeapAlloc(h, NULL, size);

	for (int i = 0; i < size / sizeof(int); ++i)
	{
		arr[i] = array_of_ints[i];
		cout << arr[i] << ", ";
	}


	/* 2 */
	int changesize, elem;
	cout << "\nСколько элементов добавить? ";
	cin >> changesize;

	arr = (int*)HeapReAlloc(h, NULL, arr, size += 4 * changesize);
	cout << "Введите элементы для добавления: \n";

	for (int k = size / 4 - changesize; k < size / 4; k++)
	{
		cin >> arr[k];
	}

	cout << "Массив: \n";
	for (int i = 0; i < size / 4; i++)
		cout << arr[i] << ", ";



	/* 3 */
	cout << "\n\n\nСколько элементов справа удалить? ";
	cin >> changesize;
	arr = (int*)HeapReAlloc(h, NULL, arr, size -= 4 * changesize);

	cout << "Массив: \n";
	for (int i = 0; i < size / 4; i++)
		cout << arr[i] << ", ";



	/* 4 */
	int index, value;
	cout << "\n\n\nВведите индекс вставки: ";
	cin >> index;
	cout << "Введите элемент для вставки: ";
	cin >> value;

	arr = (int*)HeapReAlloc(h, NULL, arr, size += 4);

	for (int i = size / 4; i > index; --i)
	{
		arr[i] = arr[i - 1];
	}
	arr[index] = value;

	cout << "Массив: \n";
	for (int i = 0; i < size / 4; i++)
		cout << arr[i] << ", ";




	/* 5 */
	int idx;
	cout << "\n\n\nВведите индекс для удаления: ";
	cin >> idx;

	arr = (int*)HeapReAlloc(h, NULL, arr, size -= 4);

	for (int i = idx; i < size / 4; ++i)
	{
		arr[i] = arr[i + 1];
	}
	cout << "Массив: \n";
	for (int i = 0; i < size / 4; i++)
		cout << arr[i] << ", ";



	//while (true)
	//{
	//	int choice;
	//	system("close");
	//	cout << "Введите номер задания:\n";
	//	cout << "2. Добавить новый элемент справа\n";
	//	cout << "3. Удалить элемент справа\n";
	//	cout << "4. Вставить элемент внутрь + сдвиг вправо\n";
	//	cout << "5. Удалить элемент внутри + сдвиг влево\n";
	//	cin >> choice;
	//	switch (choice)
	//	{
	//	case 2: goto a; break;
	//	case 3: goto b; break;
	//	case 4: goto c; break;
	//	case 5: goto d; break;
	//	}
	//}
	cout << "\n\n";
	system("pause");
	return 0;
}

