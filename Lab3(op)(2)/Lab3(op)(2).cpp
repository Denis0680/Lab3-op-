#include <iostream>

int main() {
	const int Max_rows = 10; // ����������� ������� �����
	const int Max_cols = 10; // ����������� ������� ��������

	int matrix[Max_rows][Max_cols]{
		{1, 2, 3},
		{7, 0, 700},
		{8, 700, 40},
		{30, 20, 50}
	};

	int rows = 4; //������� �����
	int cols = 3; //������� ��������

	int zerow = 0;
	for (int i = 0; i < rows; ++i)
	{
		bool hasZero = true;

		for (int l = 0; l < cols; ++l)
		{
			if (matrix[i][l] == 0)
			{
				hasZero = false;
				break;
			}
		}
		if (hasZero) {
			zerow++;
		}
	}
	std::cout << "rows without 0: " << zerow << '\n';

	int MaxRepeatedNum = -1; //����������� ����� ��� ����������� ����� 1 ����
	int MaxRep = 1; //����������� ������� ���������

	for (int i = 0; i < rows; ++i)
	{
		for (int l = 0; l < cols; ++l) {
			int CurrentNum = matrix[i][l];
			int CurrentRep = 1;

			for (int y = i + 1; y < rows; ++y) {
				for (int j = 0; j < cols; ++j) {
					if (matrix[y][j] == CurrentNum) {
						CurrentRep++;
					}
				}
			}
			if (CurrentRep > 1 && CurrentRep > MaxRep) {
				MaxRepeatedNum = CurrentNum;
				MaxRep = CurrentRep;
			}
		}
	}
	if (MaxRepeatedNum != -1) {
		std::cout << "max repeated number: " << MaxRepeatedNum << '\n';
	}
	else { std::cout << "ERROR"; }
}
