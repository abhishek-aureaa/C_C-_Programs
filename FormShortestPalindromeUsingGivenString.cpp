// NewAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 1

/*cccc*/
bool palindrome(std::string st)
{
	const char* str = st.c_str();
	int i = 0;
	int j = strlen(str) - 1;
	for (;i <= j; i++, j--)
	{
		if (str[i] != str[j])
		{
			return false;
		}
	}
	return true;
}

std::string buildPalindrome(std::string st) {

	if (palindrome(st))
	{
		//std::cout<<st;
		return st;
	}

	int i = 0;
	int j = strlen(st.c_str()) - 1;
	bool isPalin = false;
	char* st_new = NULL;
	for (;i < j;i++)
	{
		isPalin = palindrome(st.c_str() + i);
		const char* sub_palin = st.c_str() + i;

		
		if (isPalin)
		{
			const char* org_str = st.c_str();
			char* temp = (char*)malloc(strlen(org_str));

			strcpy(temp, org_str);
			st_new = (char*)malloc(strlen(org_str) + i - 1);
			strcpy(st_new, org_str);
			int m = 0;
			int len = strlen(org_str);
			for (int k = i - 1; k >= 0 &&  m <= i - 1; k--, m++)
			{
				char c = *(temp + k);
				*(st_new + len + m) = c;
				//st_new[len + m] = c;
				//*(st_new + m) = *(temp + k);
			}
			*(st_new + len + m + 1) = '\0';
			char* final  = (char*)malloc(strlen(st_new));
			memset(final, '\0', strlen(final));
			strncpy(final, st_new, strlen(st_new) - 1);
			return std::string(final);
		}
	}
		const char* org_str = st.c_str();
		char* temp = (char*)malloc(2 * strlen(org_str));
		memset(temp, '\0', 2 * strlen(org_str));
		strcpy(temp, org_str);
		int len = strlen(temp);

		i = 0;
		for (int k = len - 2; k >= 0, i < len - 1; k--, i++)
		{
			char c = org_str[k];
			*(temp + len + i) = c;
		}
		return std::string(temp);
}



int main()
{
  //  std::cout << "Hello World!\n";
	//std::string temp =  buildPalindrome(std::string st)
	//std::string temp = buildPalindrome("abcdc");
	//std::string temp = buildPalindrome("abcdc");
	/*
	temp = buildPalindrome("abcded");
	std::cout << temp<<std::endl;
	temp = buildPalindrome("abc");
	std::cout << temp <<std::endl;
	*/
	//std::string temp = buildPalindrome("abc");
	std::string temp = buildPalindrome("aba");
	std::cout << temp << std::endl;
}

