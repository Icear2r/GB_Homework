#include <iostream>
namespace MyLib {

	void InitArray(float* array, const size_t n)
	{
		std::cout << "Set array" << std::endl;

		for (int i = 0; i < n; i++)
		{
			float j{ 0 };
			
			std::cin >> j;

			*(array + i) = j;
		}
	}

	void PrintArray(float* array, const size_t n)
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << *(array + i) << " ";
		}

		std::cout << std::endl;
	}

	void SpecialFunc(float* array, const size_t n)
	{
		int j = 0, k = 0;

		for (int i = 0; i < n; i++)
		{
			if (*(array + i) > 0) j++;
			else if (*(array + i) < 0) k++;
		}

		std::cout << "There are " << j << " positiv numbers in array" << std::endl;

		std::cout << "There are " << k << " negativ numbers in array" << std::endl;
	}
}