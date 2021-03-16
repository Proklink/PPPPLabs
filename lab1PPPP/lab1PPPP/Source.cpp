#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int** allocMatrix(int row, int colomn) {
	int** Matrix = new int* [row];
	for (int i = 0; i < row; i++)
		Matrix[i] = new int[colomn];

	return Matrix;
}

int** callocMatrix(int row, int colomn) {
	int** Matrix = new int* [row];
	for (int i = 0; i < row; i++)
	{
		Matrix[i] = new int[colomn];
		for (int j = 0; j < colomn; j++)
			Matrix[i][j] = 0;
	}

	return Matrix;
}

void initMatrix(int **Matrix, int row, int colomn, bool isHandInput) {

	if (isHandInput) 
		for (int i = 0; i < row; i++)
			for (int j = 0; j < colomn; j++)
				cin >> Matrix[i][j];
	else 
		for (int i = 0; i < row; i++)
			for (int j = 0; j < colomn; j++)
				Matrix[i][j] = rand() % 10;
	

}

void printMatrix(int** Matrix, int row, int colomn) {

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < colomn; j++)
			cout << Matrix[i][j] << " ";
		cout << endl;
	}

}

void modifyMatrix(int **modifiedMatrix, int **sourceMatrix, int rowModifiedMatrix, int colomnModifiedMatrix) {
	for (int i = 0; i < rowModifiedMatrix; i++)
	{
		for (int j = 0; j < colomnModifiedMatrix; j++)
			modifiedMatrix[i][j] = sourceMatrix[i][j];
	}
}

int** formSubMatrix(int** sourceMatrix, int size, int leftSummand, int rightSummand) {

	int** subMatrix = allocMatrix(size, size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			subMatrix[i][j] = sourceMatrix[i + leftSummand][j + rightSummand];
	}

	return subMatrix;

}

void alligmentBoundaries(int size, int **Matrix, int *resultMatrixSide) {
	int countNullCells = 0;

	for (int i = 0; i < size; i++)
	{
		countNullCells = 0;
		for (int j = 0; j < size; j++)
		{
			if (Matrix[i][j] != 0)
			{
				countNullCells++;
				*resultMatrixSide = 100;
			}
		}
		if (countNullCells == 0 && i < *resultMatrixSide)
		{
			*resultMatrixSide = i;
		}
	}
}

void freeMemory(int **Array, int size) {

	for (int i = 0; i < size; i++)
		delete[] Array[i];

}

void initMatrixSize(int *row, int *colomn) {

	do
	{
		cout << "Введите размеры первой матрицы\n";
		cin >> *row >> *colomn;
	} while (*row <= 0 || *colomn <= 0);
}

void initTwoMayrix(int ** Matrix_1, int ** Matrix_2, int rowMatrxi_1, int colomnMatrxi_1, int rowMatrxi_2, int colomnMatrxi_2, bool isHandInput) {
	initMatrix(Matrix_1, rowMatrxi_1, colomnMatrxi_1, isHandInput);
	initMatrix(Matrix_2, rowMatrxi_2, colomnMatrxi_2, isHandInput);

	cout << "\nМатрица 1\n\n";
	printMatrix(Matrix_1, rowMatrxi_1, colomnMatrxi_1);

	cout << "\nМатрица 2\n\n";
	printMatrix(Matrix_2, rowMatrxi_2, colomnMatrxi_2);
}

void main()
{
	srand(time(NULL));
	int rowMatrxi_1, colomnMatrxi_1, rowMatrxi_2, colomnMatrxi_2, wayToFillMatrix, changedSize = 2;
	system("chcp 1251");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Ввод размеров матрицы пользователем////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	initMatrixSize(&rowMatrxi_1, &colomnMatrxi_1);
	initMatrixSize(&rowMatrxi_2, &colomnMatrxi_2);

	int** Matrix_1 = allocMatrix(rowMatrxi_1, colomnMatrxi_1);
	int** Matrix_2 = allocMatrix(rowMatrxi_2, colomnMatrxi_2);

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выбор способа заполнения и заполнение матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Выберите способ заполнения матриц\n" <<
			"1 - Вручную \n2 - Случайным образом\n";
		cin >> wayToFillMatrix;
	} while (wayToFillMatrix < 1 || wayToFillMatrix > 2);
	
	switch (wayToFillMatrix)
	{
	case 1:
		initTwoMayrix(Matrix_1, Matrix_2, rowMatrxi_1, colomnMatrxi_1, rowMatrxi_2, colomnMatrxi_2, true);
		break;
	case 2:
		initTwoMayrix(Matrix_1, Matrix_2, rowMatrxi_1, colomnMatrxi_1, rowMatrxi_2, colomnMatrxi_2, false);
		break;
	}

	///////////////////////////////////////////////////////////////////////////////
	/////////////////Приведение матриц к требуемому размеру////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	while (changedSize < rowMatrxi_1 || changedSize < rowMatrxi_2 || changedSize < colomnMatrxi_1 || changedSize < colomnMatrxi_2)
		changedSize *= 2;

	int** modifiedMatrix_1 = callocMatrix(changedSize, changedSize);
	int** modifiedMatrix_2 = callocMatrix(changedSize, changedSize);
	
	modifyMatrix(modifiedMatrix_1, Matrix_1, rowMatrxi_1, colomnMatrxi_1);
	modifyMatrix(modifiedMatrix_2, Matrix_2, rowMatrxi_2, colomnMatrxi_2);
	

	cout << "Приведенные матрицы\n";
	cout << "\nМатрица 1\n\n";

	printMatrix(modifiedMatrix_1, changedSize, changedSize);
	cout << "\nМатрица 2\n\n";
	printMatrix(modifiedMatrix_2, changedSize, changedSize);

	///////////////////////////////////////////////////////////////////////////////
	///////////////Разбиение матриц на подматрицы и их заполнение//////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** subMatrix_1 = formSubMatrix(modifiedMatrix_1, changedSize / 2, 0, 0);
	int** subMatrix_2 = formSubMatrix(modifiedMatrix_1, changedSize / 2, 0, changedSize / 2);
	int** subMatrix_3 = formSubMatrix(modifiedMatrix_1, changedSize / 2, changedSize / 2, 0);
	int** subMatrix_4 = formSubMatrix(modifiedMatrix_1, changedSize / 2, changedSize / 2, changedSize / 2);
	int** subMatrix_5 = formSubMatrix(modifiedMatrix_2, changedSize / 2, 0, 0);
	int** subMatrix_6 = formSubMatrix(modifiedMatrix_2, changedSize / 2, 0, changedSize / 2);
	int** subMatrix_7 = formSubMatrix(modifiedMatrix_2, changedSize / 2, changedSize / 2, 0);
	int** subMatrix_8 = formSubMatrix(modifiedMatrix_2, changedSize / 2, changedSize / 2, changedSize / 2);

	///////////////////////////////////////////////////////////////////////////////
	////////////////////////Создание промежуточных матриц//////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** intermediateMatrix_1 = allocMatrix(changedSize / 2, changedSize / 2);
	int** intermediateMatrix_2 = allocMatrix(changedSize / 2, changedSize / 2);
	int** intermediateMatrix_3 = allocMatrix(changedSize / 2, changedSize / 2);
	int** intermediateMatrix_4 = allocMatrix(changedSize / 2, changedSize / 2);
	int** intermediateMatrix_5 = allocMatrix(changedSize / 2, changedSize / 2);
	int** intermediateMatrix_6 = allocMatrix(changedSize / 2, changedSize / 2);
	int** intermediateMatrix_7 = allocMatrix(changedSize / 2, changedSize / 2);

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Вычисление значений промежуточных матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < changedSize / 2; i++)
	{
		for (int j = 0; j < changedSize / 2; j++)
		{
			intermediateMatrix_1[i][j] = intermediateMatrix_2[i][j] = intermediateMatrix_3[i][j] = intermediateMatrix_4[i][j] = intermediateMatrix_5[i][j] = intermediateMatrix_6[i][j] = intermediateMatrix_7[i][j] = 0;
	
			for (int z = 0; z < changedSize / 2; z++)
			{
				intermediateMatrix_1[i][j] += (subMatrix_1[i][z] + subMatrix_4[i][z]) * (subMatrix_5[z][j] + subMatrix_8[z][j]);
				intermediateMatrix_2[i][j] += (subMatrix_3[i][z] + subMatrix_4[i][z]) * subMatrix_5[z][j];
				intermediateMatrix_3[i][j] += subMatrix_1[i][z] * (subMatrix_6[z][j] - subMatrix_8[z][j]);
				intermediateMatrix_4[i][j] += subMatrix_4[i][z] * (subMatrix_7[z][j] - subMatrix_5[z][j]);
				intermediateMatrix_5[i][j] += (subMatrix_1[i][z] + subMatrix_2[i][z]) * subMatrix_8[z][j];
				intermediateMatrix_6[i][j] += (subMatrix_3[i][z] - subMatrix_1[i][z]) * (subMatrix_5[z][j] + subMatrix_6[z][j]);
				intermediateMatrix_7[i][j] += (subMatrix_2[i][z] - subMatrix_4[i][z]) * (subMatrix_7[z][j] + subMatrix_8[z][j]);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////Создание вспомогательных матриц/////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** auxiliaryMatrix_1 = allocMatrix(changedSize / 2, changedSize / 2);
	int** auxiliaryMatrix_2 = allocMatrix(changedSize / 2, changedSize / 2);
	int** auxiliaryMatrix_3 = allocMatrix(changedSize / 2, changedSize / 2);
	int** auxiliaryMatrix_4 = allocMatrix(changedSize / 2, changedSize / 2);

	///////////////////////////////////////////////////////////////////////////////
	////////////Подсчет значений вспомогательных матриц из промежуточных///////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < changedSize / 2; i++)
	{
		for (int j = 0; j < changedSize / 2; j++)
		{
			auxiliaryMatrix_1[i][j] = intermediateMatrix_1[i][j] + intermediateMatrix_4[i][j] - intermediateMatrix_5[i][j] + intermediateMatrix_7[i][j];
			auxiliaryMatrix_2[i][j] = intermediateMatrix_3[i][j] + intermediateMatrix_5[i][j];
			auxiliaryMatrix_3[i][j] = intermediateMatrix_2[i][j] + intermediateMatrix_4[i][j];
			auxiliaryMatrix_4[i][j] = intermediateMatrix_1[i][j] - intermediateMatrix_2[i][j] + intermediateMatrix_3[i][j] + intermediateMatrix_6[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Создание результирующей матрицы/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** resultMatrix = allocMatrix(changedSize, changedSize);

	///////////////////////////////////////////////////////////////////////////////
	///////Занесение информации из вспомогательных матриц в результирующую/////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < changedSize / 2; i++)
	{
		for (int j = 0; j < changedSize / 2; j++)
		{
			resultMatrix[i][j] = auxiliaryMatrix_1[i][j];
			resultMatrix[i][j + changedSize / 2] = auxiliaryMatrix_2[i][j];
			resultMatrix[i + changedSize / 2][j] = auxiliaryMatrix_3[i][j];
			resultMatrix[i + changedSize / 2][j + changedSize / 2] = auxiliaryMatrix_4[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выравнивание границ результирующей матрицы/////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int resultMatrixRow = 100, resultMatrixColomn = 100;

	alligmentBoundaries(changedSize, resultMatrix, &resultMatrixRow);
	alligmentBoundaries(changedSize, resultMatrix, &resultMatrixColomn);

	int** finalMatrix = allocMatrix(resultMatrixRow, resultMatrixColomn);
	modifyMatrix(finalMatrix, resultMatrix, resultMatrixRow, resultMatrixColomn);

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Вывод результирующей матрицы////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	cout << "\nРезультирующая матрица\n\n";
	printMatrix(finalMatrix, resultMatrixRow, resultMatrixColomn);

	system("pause");

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////Очистка динамической памяти///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	freeMemory(Matrix_1, rowMatrxi_1);
	freeMemory(Matrix_2, rowMatrxi_2);

	for (int i = 0; i < changedSize; i++)
	{
		delete[] modifiedMatrix_1[i];
		delete[] modifiedMatrix_2[i];
		delete[] resultMatrix[i];
	}
	freeMemory(finalMatrix, resultMatrixRow);
	
	for (int i = 0; i < changedSize / 2; i++)
	{
		delete[] subMatrix_1[i];
		delete[] subMatrix_2[i];
		delete[] subMatrix_3[i];
		delete[] subMatrix_4[i];
		delete[] subMatrix_5[i];
		delete[] subMatrix_6[i];
		delete[] subMatrix_7[i];
		delete[] subMatrix_8[i];
		delete[] auxiliaryMatrix_1[i];
		delete[] auxiliaryMatrix_2[i];
		delete[] auxiliaryMatrix_3[i];
		delete[] auxiliaryMatrix_4[i];
		delete[] intermediateMatrix_1[i];
		delete[] intermediateMatrix_2[i];
		delete[] intermediateMatrix_3[i];
		delete[] intermediateMatrix_4[i];
		delete[] intermediateMatrix_5[i];
		delete[] intermediateMatrix_6[i];
		delete[] intermediateMatrix_7[i];
	}
	delete[] Matrix_1, Matrix_2, modifiedMatrix_1, modifiedMatrix_2, resultMatrix, finalMatrix;
	delete[] subMatrix_1, subMatrix_2, subMatrix_3, subMatrix_4, subMatrix_5, subMatrix_6, subMatrix_7, subMatrix_8, auxiliaryMatrix_1, auxiliaryMatrix_2, auxiliaryMatrix_3, auxiliaryMatrix_4;
	delete[] intermediateMatrix_1, intermediateMatrix_2, intermediateMatrix_3, intermediateMatrix_4, intermediateMatrix_5, intermediateMatrix_6, intermediateMatrix_7;
}