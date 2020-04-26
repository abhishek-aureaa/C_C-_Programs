// NewAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 1


int Moduls_Sum_Product(int arr[], int max_index, int modulas_val)
{
	int SUM = 0;
	for (int i = 0; i <= max_index; i++)
	{
		arr[i] = (arr[i] % modulas_val);
		SUM += arr[i];
	}
	return (SUM%modulas_val);
}

int main()
{
	int arr[] = { 12, 24, 8, 6 };
	int ret = Moduls_Sum_Product(arr, 3, 12);
	std::cout << ret;


}

