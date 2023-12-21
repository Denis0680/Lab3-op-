#include <iostream>

int main() {
	const int N = 6;
	int arr[N] = { -1,2,3,-4,5,6 };

	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		if (arr[i] < 0)
		{
			sum += arr[i];
		}
	}
	std::cout << "The sum of all negative elements: " << sum << '\n';

	int maxInd = 0;
	int minInd = 0;

	for (int i = 1; i < N; ++i)
	{
		if (arr[i] > arr[maxInd])
		{
			maxInd = i;
		}
		if (arr[i] < arr[minInd])
		{
			minInd = i;
		}
	}

	int start = std::min(maxInd, minInd) + 1;
	int end = std::max(maxInd, minInd);

	int res = 1;
	for (int i = start; i < end; ++i)
	{
		res *= arr[i];
	}
	std::cout << "The prod of the elem between the max and min value: " << res << '\n';
}