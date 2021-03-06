#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void swap(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int* initArray(int length)
{
	int* newArray = new int[length];
	for (int i = 0; i < length; ++i)
	{
		newArray[i] = rand() % 100;
	}
	return newArray;
}

void printArray(int *theArray, int length)
{
	printf("\n\n");
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", theArray[i]);
	}
	printf("\n\n");
}

void quickSort(int* theArray, int firstIndex, int lastIndex)
{
	if (firstIndex >= lastIndex)
	{
		return;
	}
	int index = firstIndex;
	int element = theArray[firstIndex];
	for (int i = firstIndex; i <= lastIndex; ++i)
	{
		if (theArray[i] < element)
		{
			swap(theArray[i], theArray[index]);
			++index;
		}
	}
	if (index == firstIndex)
	{
		++index;
	}
	quickSort(theArray, firstIndex, index - 1);
	quickSort(theArray, index, lastIndex);
}

int mostFrequentElement(int *theArray, int length)
{
	quickSort(theArray, 0, length - 1);
	int element = 0;
	int tmpElement = theArray[0];
	int frequency = 0;
	int tmpFrequency = 1;
	for (int i = 1; i < length; ++i)
	{
		if (theArray[i] == tmpElement)
		{
			tmpFrequency++;
		}
		else
		{
			if (tmpFrequency > frequency)
			{
				element = tmpElement;
				frequency = tmpFrequency;
			}
			tmpFrequency = 1;
			tmpElement = theArray[i];
		}
	}
	if (tmpFrequency > frequency)
	{
		return tmpElement;
	}
	else
	{
		return element;
	}
}

void test()
{
	printf("���������...\n\n");
	int* testArray = new int[16]{ 100, 8123, 31, 8213, 52, 3, 8123, 3, 24803, 24803, 3, 1, 90, 90, 8123, 8123 };
	printArray(testArray, 16);
	int result = mostFrequentElement(testArray, 16);
	delete[] testArray;
	printf("������������ �������: %d\n", result);
	result == 8123 ? printf("���� �������!\n\n") : printf("���� �� �������, ����� 8123\n\n");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));
	test();
	int length = 0;
	printf("������� ����� �������: ");
	scanf("%d", &length);
	int *myArray = initArray(length);
	printf("��� ������:");
	printArray(myArray, length);
	printf("�������� ����� ������������� ������� � �������: %d\n", mostFrequentElement(myArray, length));
	delete[] myArray;
	return 0;
}
