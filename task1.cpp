#include<iostream>
#include<fstream>
using namespace std;
void SetMatrixFromUser(float**&Matrix, int& Rows, int& Colums);
int getLength(char* Array);
char* AddDotTxt(char* Name);
int getRows(const char* Filename);
int getCol(const char* Filename);
void CopyDataCol(float* OldArray, float* newArray, int size);
void RegrowbyColumns(float*& Array, int size);
void DisplayMatrix(float** Matrix, int row, int col);
void WritingMatrix(float** Matrix, int row, int col);
float** SetMatrixFromFile(char* FileName, float** Matrix, int& Rows, int& Colums);
void SumofMatrix(float** Matrix, int row, int col);
void ProductofMatrix(float** Matrix, int row, int col);
void RowWiseAverageofMatrix(float** Matrix, int row, int col);
void ColWiseAverageofMatrix(float** Matrix, int row, int col);
float** RowWiseSortingofMatrix(float** Matrix, int row, int col);
float** ColWiseSortingofMatrix(float** oldMatrix, int row, int col);
void AverageofMatrix(float** Matrix, int row, int col);
float** ScalarMatrixAddition(float**oldMatrix, int row, int col, int Number);
float** ScalarMatrixSubtraction(float**oldMatrix, int row, int col, int Number);
float** ScalarMatrixMultiplication(float**oldMatrix, int row, int col, int Number);
float** ScalarMatrixDivision(float**oldMatrix, int row, int col, int Number);
void MatrixTranspose(float**Matrix, int row, int col);
float** CreateMatrixFromFile(int& Rows, int& Colums);
void DeleteMatrix(float**& Matrix, int row);
void AdditionofTwoMatrix(float** Matrix1, float**Matrix2, int row, int col, int row2, int col2);
void AdditionofTwoMatrixFile(float** Matrix1, float**Matrix2, int row, int col, int row2, int col2);
void SubtractionofTwoMatrix(float** Matrix1, float**Matrix2, int row, int col, int row2, int col2);
void SubtractionofTwoMatrixFile(float** Matrix1, float**Matrix2, int row, int col, int row2, int col2);
void MultiplicationofTwoMatrix(float** Matrix1, float**Matrix2, int row, int col, int row2, int col2);
void MultiplicationofTwoMatrixFile(float** Matrix1, float**Matrix2, int row, int col, int row2, int col2);
float** CopyMatrixData(float** NewMatrix, float** oldMatrix, int row, int col);
float** Create2DMatrix(int row, int col);
void Determinant(float** Matrix, int row, int col);
void DeterminantFile(float** Matrix, int row, int col);
void InverseofMatrix(float** oldMatrix, int row, int col);
void DisplayonFileorConsole(bool usingFile, float ** Matrix, int Rows, int Colums, float** NewMatrix);
void InverseofMatrixFile(float** oldMatrix, int row, int col);
void MatrixTransposeFile(float**Matrix, int row, int col);
int main()
{
	/*1. Sum of Matrix(sum of all values)
	2. Product of Matrix(product of all values)
	3. Row - wise Average
	4. Column - wise Average
	5. Average or whole Matrix
	6. Row - wise sorting of Matrix
	7. Column - wise sorting of Matrix
	8. Scalar Matrix Addition
	9. Addition of two Matrices
	10. Scalar Matrix Subtraction
	11. Subtraction of two Matrices
	12. Scalar Matrix Multiplication
	13. Multiplication of two Matrices
	14. Scalar Matrix Division
	15. Matrix transpose
	16. Matrix determinant
	17. Matrix Inverse*/

	int Colums = 0;
	int Rows = 0;
	int Colums2 = 0;
	int Rows2 = 0;
	float** Matrix = nullptr;
	float** Matrix2 = nullptr;
	char* Filename = new char[100]{'\0'};
	bool usingFile = false;
	int Option = 0;
	cout << "From which source do you want to enter DATA " << endl;
	cout << "Press 1 to enter data from file " << endl;
	cout << "Press 2 to enter data from user " << endl;

	char dataoption = '\0';
	cin >> dataoption;

	while (dataoption != '1' && dataoption != '2') {
		cout << "WRONG INPUT" << endl;
		cout << "Please enter again" << endl;
		cin >> dataoption;
	}
	if (dataoption == '1')
	{
		cout << "Enter FileName for Matrix 1" << endl;
		cin >> Filename;
		ifstream fin(AddDotTxt(Filename));
		while (!fin.is_open())
		{
			cout << "Wrong Fill Enter Again" << endl;
			cin >> Filename;
			fin.close();
			fin.open(AddDotTxt(Filename));
		}
		Rows = getRows(AddDotTxt(Filename));
		Colums = getCol(AddDotTxt(Filename));
		Matrix = SetMatrixFromFile(AddDotTxt(Filename), Matrix, Rows, Colums);

		cout << "Enter FileName for Matrix 2" << endl;
		cin >> Filename;
		fin.close();
		fin.open(AddDotTxt(Filename));
		while (!fin.is_open())
		{
			cout << "Wrong Fill Enter Again" << endl;
			cin >> Filename;
			fin.close();
			fin.open(AddDotTxt(Filename));
		}
		Rows2 = getRows(AddDotTxt(Filename));
		Colums2 = getCol(AddDotTxt(Filename));
		Matrix2 = SetMatrixFromFile(AddDotTxt(Filename), Matrix2, Rows2, Colums2);
		usingFile = true;
	}
	else if (dataoption == '2')
	{
		cout << "Enter Matrix no 1" << endl;
		SetMatrixFromUser(Matrix, Rows, Colums);
		system("CLS");
		cout << "Enter Matrix no 2" << endl;
		SetMatrixFromUser(Matrix2, Rows2, Colums2);

	}

	while (1)
	{

		system("pause");
		system("CLS");
		cout << "1. Sum of Matrix (sum of all values)" << endl;
		cout << "2. Product of Matrix (product of all values)" << endl;
		cout << "3. Row-wise Average" << endl;
		cout << "4. Column-wise Average" << endl;
		cout << "5. Average of Whole Matrix" << endl;
		cout << "6. Row-wise Sorting of Matrix" << endl;
		cout << "7. Column-wise Sorting of Matrix" << endl;
		cout << "8. Scalar Matrix Addition" << endl;
		cout << "9. Addition of Two Matrices" << endl;
		cout << "10. Scalar Matrix Subtraction" << endl;
		cout << "11. Subtraction of Two Matrices" << endl;
		cout << "12. Scalar Matrix Multiplication" << endl;
		cout << "13. Multiplication of Two Matrices" << endl;
		cout << "14. Scalar Matrix Division" << endl;
		cout << "15. Matrix Transpose" << endl;
		cout << "16. Matrix determinant" << endl;
		cout << "17. Matrix Inverse" << endl;
		cout << "18. To Exit Program" << endl;
		cout << "Enter your Option" << endl;
		cin >> Option;

		if (Option == 1)
		{
			// Code for Sum of Matrix

			DisplayMatrix(Matrix, Rows, Colums);
			SumofMatrix(Matrix, Rows, Colums);
		}
		else if (Option == 2)
		{
			// Code for Product of Matrix
			DisplayMatrix(Matrix, Rows, Colums);
			ProductofMatrix(Matrix, Rows, Colums);
		}
		else if (Option == 3)
		{
			// Code for Row-wise Average
			DisplayMatrix(Matrix, Rows, Colums);
			RowWiseAverageofMatrix(Matrix, Rows, Colums);
		}
		else if (Option == 4)
		{
			// Code for Column-wise Average
			DisplayMatrix(Matrix, Rows, Colums);
			ColWiseAverageofMatrix(Matrix, Rows, Colums);
		}
		else if (Option == 5)
		{
			// Code for Average of Whole Matrix
			DisplayMatrix(Matrix, Rows, Colums);
			AverageofMatrix(Matrix, Rows, Colums);
		}
		else if (Option == 6)
		{
			// Code for Row-wise Sorting of Matrix
			float** NewMatrix = RowWiseSortingofMatrix(Matrix, Rows, Colums);

			int c = 0;
			cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
			cout << "Enter your choice : ";
			cin >> c;
			cout << endl;
			for (int i = 0; c <= 0 || c > 2; i++)
			{
				cout << "!! Invalid Input !!" << endl;
				cout << "!! Please input between 1 to 2 !!" << endl;
				cin >> c;
			}
			if (c == 1)usingFile = true;
			else usingFile = false;
			DisplayonFileorConsole(usingFile, Matrix, Rows, Colums, NewMatrix);


		}
		else if (Option == 7)
		{
			// Code for Column-wise Sorting of Matrix
			float** NewMatrix = ColWiseSortingofMatrix(Matrix, Rows, Colums);
			int c = 0;
			cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
			cout << "Enter your choice : ";
			cin >> c;
			cout << endl;
			for (int i = 0; c <= 0 || c > 2; i++)
			{
				cout << "!! Invalid Input !!" << endl;
				cout << "!! Please input between 1 to 2 !!" << endl;
				cin >> c;
			}
			if (c == 1)usingFile = true;
			else usingFile = false;
			DisplayonFileorConsole(usingFile, Matrix, Rows, Colums, NewMatrix);
		}
		else if (Option == 8)
		{
			// Code for Scalar Matrix Addition
			int ScalarValue = 0;
			cout << "Enter Scalar Value" << endl;
			cin >> ScalarValue;
			float** NewMatrix = ScalarMatrixAddition(Matrix, Rows, Colums, ScalarValue);
			int c = 0;
			cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
			cout << "Enter your choice : ";
			cin >> c;
			cout << endl;
			for (int i = 0; c <= 0 || c > 2; i++)
			{
				cout << "!! Invalid Input !!" << endl;
				cout << "!! Please input between 1 to 2 !!" << endl;
				cin >> c;
			}
			if (c == 1)usingFile = true;
			else usingFile = false;
			DisplayonFileorConsole(usingFile, Matrix, Rows, Colums, NewMatrix);
		}
		else if (Option == 9)
		{
			// Code for Addition of Two Matrices
			int c = 0;
			cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
			cout << "Enter your choice : ";
			cin >> c;
			cout << endl;
			for (int i = 0; c <= 0 || c > 2; i++)
			{
				cout << "!! Invalid Input !!" << endl;
				cout << "!! Please input between 1 to 2 !!" << endl;
				cin >> c;
			}
			if (c == 1)usingFile = true;
			else usingFile = false;
			if (usingFile == false)
			{
				cout << "Matrix no 1" << endl;
				DisplayMatrix(Matrix, Rows, Colums);
				cout << "Matrix no 2" << endl;
				DisplayMatrix(Matrix2, Rows2, Colums2);
				AdditionofTwoMatrix(Matrix, Matrix2, Rows, Colums, Rows2, Colums2);
			}
			else
			{
				ofstream fout("output_f1.txt");
				fout << "Matrix no 1" << endl;
				fout.close();
				WritingMatrix(Matrix, Rows, Colums);
				fout.open("output_f1.txt", ios::app);
				fout << "Matrix no 2" << endl;
				fout.close();
				WritingMatrix(Matrix2, Rows2, Colums2);
				AdditionofTwoMatrixFile(Matrix, Matrix2, Rows, Colums, Rows2, Colums2);
			}
		}
		else if (Option == 10)
		{
			// Code for Scalar Matrix Subtraction

			int ScalarValue = 0;
			cout << "Enter Scalar Value" << endl;
			cin >> ScalarValue;
			float** NewMatrix = ScalarMatrixSubtraction(Matrix, Rows, Colums, ScalarValue);
			int c = 0;
			cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
			cout << "Enter your choice : ";
			cin >> c;
			cout << endl;
			for (int i = 0; c <= 0 || c > 2; i++)
			{
				cout << "!! Invalid Input !!" << endl;
				cout << "!! Please input between 1 to 2 !!" << endl;
				cin >> c;
			}
			if (c == 1)usingFile = true;
			else usingFile = false;
			DisplayonFileorConsole(usingFile, Matrix, Rows, Colums, NewMatrix);
		}
		else if (Option == 11)
		{
			// Code for Subtraction of Two Matrices
			int c = 0;
			cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
			cout << "Enter your choice : ";
			cin >> c;
			cout << endl;
			for (int i = 0; c <= 0 || c > 2; i++)
			{
				cout << "!! Invalid Input !!" << endl;
				cout << "!! Please input between 1 to 2 !!" << endl;
				cin >> c;
			}
			if (c == 1)usingFile = true;
			else usingFile = false;
			if (usingFile == false)
			{
				cout << "Matrix no 1" << endl;
				DisplayMatrix(Matrix, Rows, Colums);
				cout << "Matrix no 2" << endl;
				DisplayMatrix(Matrix2, Rows2, Colums2);
				SubtractionofTwoMatrix(Matrix, Matrix2, Rows, Colums, Rows2, Colums2);
			}
			else
			{
				ofstream fout("output_f1.txt");
				fout << "Matrix no 1" << endl;
				fout.close();
				WritingMatrix(Matrix, Rows, Colums);
				fout.open("output_f1.txt", ios::app);
				fout << "Matrix no 2" << endl;
				fout.close();
				WritingMatrix(Matrix2, Rows2, Colums2);
				SubtractionofTwoMatrixFile(Matrix, Matrix2, Rows, Colums, Rows2, Colums2);
			}
		}
		else if (Option == 12)
		{
			// Code for Scalar Matrix Multiplication
			int ScalarValue = 0;
			cout << "Enter Scalar Value" << endl;
			cin >> ScalarValue;
			float** NewMatrix = ScalarMatrixMultiplication(Matrix, Rows, Colums, ScalarValue);
			int c = 0;
			cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
			cout << "Enter your choice : ";
			cin >> c;
			cout << endl;
			for (int i = 0; c <= 0 || c > 2; i++)
			{
				cout << "!! Invalid Input !!" << endl;
				cout << "!! Please input between 1 to 2 !!" << endl;
				cin >> c;
			}
			if (c == 1)usingFile = true;
			else usingFile = false;

			DisplayonFileorConsole(usingFile, Matrix, Rows, Colums, NewMatrix);
		}
		else if (Option == 13)
		{
			// Code for Multiplication of Two Matrices
			int c = 0;
			cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
			cout << "Enter your choice : ";
			cin >> c;
			cout << endl;
			for (int i = 0; c <= 0 || c > 2; i++)
			{
				cout << "!! Invalid Input !!" << endl;
				cout << "!! Please input between 1 to 2 !!" << endl;
				cin >> c;
			}
			if (c == 1)usingFile = true;
			else usingFile = false;

			if (usingFile == false)
			{
				cout << "Matrix no 1" << endl;
				DisplayMatrix(Matrix, Rows, Colums);
				cout << "Matrix no 2" << endl;
				DisplayMatrix(Matrix2, Rows2, Colums2);
				MultiplicationofTwoMatrix(Matrix, Matrix2, Rows, Colums, Rows2, Colums2);
			}
			else
			{
				ofstream fout("output_f1.txt");
				fout << "Matrix no 1" << endl;
				fout.close();
				WritingMatrix(Matrix, Rows, Colums);
				fout.open("output_f1.txt", ios::app);
				fout << "Matrix no 2" << endl;
				fout.close();
				WritingMatrix(Matrix2, Rows2, Colums2);
				MultiplicationofTwoMatrixFile(Matrix, Matrix2, Rows, Colums, Rows2, Colums2);
			}
		}
		else if (Option == 14)
		{
			// Code for Scalar Matrix Division
			int ScalarValue = 0;
			cout << "Enter Scalar Value" << endl;
			cin >> ScalarValue;
			float** NewMatrix = ScalarMatrixDivision(Matrix, Rows, Colums, ScalarValue);
			int c = 0;
			cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
			cout << "Enter your choice : ";
			cin >> c;
			cout << endl;
			for (int i = 0; c <= 0 || c > 2; i++)
			{
				cout << "!! Invalid Input !!" << endl;
				cout << "!! Please input between 1 to 2 !!" << endl;
				cin >> c;
			}
			if (c == 1)usingFile = true;
			else usingFile = false;

			DisplayonFileorConsole(usingFile, Matrix, Rows, Colums, NewMatrix);
		}
		else if (Option == 15)
		{
			// Code for Matrix Transpose
			int c = 0;
			cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
			cout << "Enter your choice : ";
			cin >> c;
			cout << endl;
			for (int i = 0; c <= 0 || c > 2; i++)
			{
				cout << "!! Invalid Input !!" << endl;
				cout << "!! Please input between 1 to 2 !!" << endl;
				cin >> c;
			}
			if (c == 1)usingFile = true;
			else usingFile = false;
			if (usingFile == false)
			{
				cout << "Original Matrix" << endl;
				DisplayMatrix(Matrix, Rows, Colums);
				cout << "Transposed Matrix" << endl;
				MatrixTranspose(Matrix, Rows, Colums);
			}
			else
			{
				ofstream fout("output_f1.txt");
				fout << "Original Matrix" << endl;
				fout.close();
				WritingMatrix(Matrix, Rows, Colums);
				fout.open("output_f1.txt", ios::app);
				fout << "Transposed Matrix" << endl;
				fout.close();
				MatrixTransposeFile(Matrix, Rows, Colums);
			}

		}
		else if (Option == 16)
		{
			// Code for Matrix Determinant
			int c = 0;
			cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
			cout << "Enter your choice : ";
			cin >> c;
			cout << endl;
			for (int i = 0; c <= 0 || c > 2; i++)
			{
				cout << "!! Invalid Input !!" << endl;
				cout << "!! Please input between 1 to 2 !!" << endl;
				cin >> c;
			}
			if (c == 1)usingFile = true;
			else usingFile = false;
			if (usingFile == false)
			{
				cout << "Original Matrix" << endl;
				DisplayMatrix(Matrix, Rows, Colums);
				Determinant(Matrix, Rows, Colums);
			}
			else
			{
				ofstream fout("output_f1.txt");
				fout << "Original Matrix" << endl;
				fout.close();
				WritingMatrix(Matrix, Rows, Colums);
				DeterminantFile(Matrix, Rows, Colums);
			}
		}
		else if (Option == 17)
		{
			// Code for Matrix Inverse
			int c = 0;
			cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
			cout << "Enter your choice : ";
			cin >> c;
			cout << endl;
			for (int i = 0; c <= 0 || c > 2; i++)
			{
				cout << "!! Invalid Input !!" << endl;
				cout << "!! Please input between 1 to 2 !!" << endl;
				cin >> c;
			}
			if (c == 1)usingFile = true;
			else usingFile = false;

			if (usingFile == false)
			{
				cout << "Original Matrix" << endl;
				DisplayMatrix(Matrix, Rows, Colums);
				cout << "Inverse Matrix" << endl;
				InverseofMatrix(Matrix, Rows, Colums);
			}
			else
			{
				ofstream fout("output_f1.txt");
				fout << "Original Matrix" << endl;
				fout.close();
				WritingMatrix(Matrix, Rows, Colums);
				fout.open("output_f1.txt", ios::app);
				fout << "Inverse Matrix" << endl;
				fout.close();
				InverseofMatrixFile(Matrix, Rows, Colums);
			}

		}
		else if (Option == 18)
		{
			cout << "PROGRAM TERMINATED!!!" << endl;
			break;
		}
		else
		{
			cout << "Invalid Option. Please choose a valid option." << endl;
		}
	}

	system("pause");
	return 0;
}
void SetMatrixFromUser(float**&Matrix, int& Rows, int& Colums){
	cout << "Enter the number of rows :";
	cin >> Rows;
	cout << "Enter the number of colums :";
	cin >> Colums;
	Matrix = new float*[Rows];
	for (int i = 0; i < Rows; i++){
		Matrix[i] = new float[Colums];
	}

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colums; j++)
		{
			cout << "matrix1[" << i << "][" << j << "] : ";
			cin >> Matrix[i][j];
		}
	}
}
int getLength(char* Array)
{
	int len = 0;
	for (int i = 0; Array[i] != '\0'; i++)len++;
	return len;
}
char* AddDotTxt(char* Name)
{
	int length = getLength(Name);
	if (Name[length - 1] != 't' || Name[length - 2] != 'x' || Name[length - 3] != 't' || Name[length - 4] != '.')
	{
		char* NewName = new char[length + 5];
		for (int i = 0; i < length; i++)NewName[i] = Name[i];
		NewName[length] = '.';
		NewName[length + 1] = 't';
		NewName[length + 2] = 'x';
		NewName[length + 3] = 't';
		NewName[length + 4] = '\0';
		return NewName;
	}
	else return Name;
}
int getRows(const char* Filename)
{
	int Count = 0;
	ifstream fin(Filename);
	char* Reader = new char[100]{'\0'};
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.getline(Reader, 100);
			Count++;
		}
	}
	else cout << "File not found" << endl;
	fin.close();
	return Count;
}
int getCol(const char* Filename)
{
	int Col = 0;
	int Count = -1;
	ifstream fin(Filename);
	char* Reader = new char[100]{'\0'};
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			Col = 0;
			fin.getline(Reader, 100);
			for (int i = 0; Reader[i] != '\0'; i++)
			{
				if (Reader[i] == ' ')Col++;
			}
			Col++;
			if (Count == -1) Count = Col;
			if (Count != Col)
			{
				cout << "Not Balanced Matrix in File" << endl;
				return -1;
			}
		}
	}
	else cout << "File not found" << endl;
	fin.close();
	return Col;
}
void CopyDataCol(float* OldArray, float* newArray, int size)
{
	for (int i = 0; i < size; i++)newArray[i] = OldArray[i];
}
void RegrowbyColumns(float*& Array, int size)
{
	float* newArray = new float[size + 1];
	if (size == 0)
	{
		Array = newArray;
		return;
	}
	CopyDataCol(Array, newArray, size);
	delete[]Array;
	Array = newArray;
}
void DisplayMatrix(float** Matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void WritingMatrix(float** Matrix, int row, int col)
{
	ofstream fout("output_f1.txt", ios::app);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			fout << Matrix[i][j] << " ";
		}
		fout << endl;
	}
	fout << endl;
}
float** SetMatrixFromFile(char* FileName, float** Matrix, int& Rows, int& Colums)
{
	ifstream fin(FileName);
	if (fin.is_open())
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Colums; j++)
			{
				if (Matrix == nullptr)
				{
					Matrix = new float*[1];
					Matrix[0] = new float[1];
					fin >> Matrix[i][j];
					continue;
				}
				RegrowbyColumns(Matrix[i], j);
				fin >> Matrix[i][j];
			}
		}
	}
	else cout << "File not found" << endl;
	DisplayMatrix(Matrix, Rows, Colums);
	return Matrix;
}
void SumofMatrix(float** Matrix, int row, int col)
{
	float Sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Sum += Matrix[i][j];
		}
	}
	cout << endl;
	int c = 0;
	cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
	cout << "Enter your choice : ";
	cin >> c;
	cout << endl;
	for (int i = 0; c <= 0 || c > 2; i++)
	{
		cout << "!! Invalid Input !!" << endl;
		cout << "!! Please input between 1 to 2 !!" << endl;
		cin >> c;
	}
	if (c == 1)
	{
		ofstream fout;
		fout.open("output_f1.txt");
		fout << "!! The Sum of the whole matrix is : " << Sum << " !!" << endl;
		fout.close();
	}
	else if (c == 2)
	{
		cout << "!! The Sum of the whole matrix is : " << Sum << " !!" << endl;
	}
}
void  ProductofMatrix(float** Matrix, int row, int col)
{
	int Product = 1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Product *= Matrix[i][j];
		}
	}
	int c = 0;
	cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
	cout << "Enter your choice : ";
	cin >> c;
	cout << endl;
	for (int i = 0; c <= 0 || c > 2; i++)
	{
		cout << "!! Invalid Input !!" << endl;
		cout << "!! Please input between 1 to 2 !!" << endl;
		cin >> c;
	}
	if (c == 1)
	{
		ofstream fout;
		fout.open("output_f1.txt");
		fout << "!! The Product of the whole matrix is : " << Product << " !!" << endl;
		fout.close();
	}
	else if (c == 2)
	{
		cout << "!! The Product of the whole matrix is : " << Product << " !!" << endl;
	}
}
void RowWiseAverageofMatrix(float** Matrix, int row, int col)
{
	float Average = 0;
	for (int i = 0; i < row; i++)
	{
		Average = 0;
		for (int j = 0; j < col; j++)
		{
			Average += Matrix[i][j];
		}
	}

	int c = 0;
	cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
	cout << "Enter your choice : ";
	cin >> c;
	cout << endl;
	for (int i = 0; c <= 0 || c > 2; i++)
	{
		cout << "!! Invalid Input !!" << endl;
		cout << "!! Please input between 1 to 2 !!" << endl;
		cin >> c;
	}
	if (c == 1)
	{
		ofstream fout;
		fout.open("output_f1.txt");
		fout << "!! The Average of the Row matrix is : " << Average / row << " !!" << endl;
		fout.close();
	}
	else if (c == 2)
	{
		cout << "!! The Average of the Row matrix is : " << Average / row << " !!" << endl;
	}
}
void ColWiseAverageofMatrix(float** Matrix, int row, int col)
{
	float Average = 0;
	for (int i = 0; i < row; i++)
	{
		Average = 0;
		for (int j = 0; j < col; j++)
		{
			Average += Matrix[j][i];
		}
	}

	int c = 0;
	cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
	cout << "Enter your choice : ";
	cin >> c;
	cout << endl;
	for (int i = 0; c <= 0 || c > 2; i++)
	{
		cout << "!! Invalid Input !!" << endl;
		cout << "!! Please input between 1 to 2 !!" << endl;
		cin >> c;
	}
	if (c == 1)
	{
		ofstream fout;
		fout.open("output_f1.txt");
		fout << "!! The Average of the Column matrix is : " << Average / col << " !!" << endl;
		fout.close();
	}
	else if (c == 2)
	{
		cout << "!! The Average of the Column matrix is : " << Average / col << " !!" << endl;
	}
}
float** CopyMatrixData(float** NewMatrix, float** oldMatrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			NewMatrix[i][j] = oldMatrix[i][j];
		}
	}
	return NewMatrix;
}
float** RowWiseSortingofMatrix(float** oldMatrix, int row, int col)
{
	float ** Matrix = Create2DMatrix(row, col);
	Matrix = CopyMatrixData(Matrix, oldMatrix, row, col);
	int Temp = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col - 1; j++)
		{
			for (int k = j + 1; k < col; k++)
			{
				if (Matrix[i][j] >Matrix[i][k])
				{
					Temp = Matrix[i][j];
					Matrix[i][j] = Matrix[i][k];
					Matrix[i][k] = Temp;
				}
			}
		}
	}
	return Matrix;
}
float** ColWiseSortingofMatrix(float** oldMatrix, int row, int col)
{
	float ** Matrix = Create2DMatrix(row, col);
	Matrix = CopyMatrixData(Matrix, oldMatrix, row, col);
	int Temp = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col - 1; j++)
		{
			for (int k = j + 1; k < col; k++)
			{
				if (Matrix[j][i] >Matrix[k][i])
				{
					Temp = Matrix[j][i];
					Matrix[j][i] = Matrix[k][i];
					Matrix[k][i] = Temp;
				}
			}
		}
	}
	return Matrix;
}
void AverageofMatrix(float** Matrix, int row, int col)
{
	float Average = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Average += Matrix[j][i];
		}
	}

	int c = 0;
	cout << "!! Press 1 to output on File || Press 2 to output on Console " << endl;
	cout << "Enter your choice : ";
	cin >> c;
	cout << endl;
	for (int i = 0; c <= 0 || c > 2; i++)
	{
		cout << "!! Invalid Input !!" << endl;
		cout << "!! Please input between 1 to 2 !!" << endl;
		cin >> c;
	}
	if (c == 1)
	{
		ofstream fout;
		fout.open("output_f1.txt");
		fout << "!! The Average of the matrix is : " << Average / (row*col) << " !!" << endl;
		fout.close();
	}
	else if (c == 2)
	{
		cout << "!! The Average of the matrix is : " << Average / (row*col) << " !!" << endl;
	}
}
float** ScalarMatrixAddition(float**oldMatrix, int row, int col, int Number)
{
	float ** Matrix = Create2DMatrix(row, col);
	Matrix = CopyMatrixData(Matrix, oldMatrix, row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Matrix[j][i] += Number;
		}
	}
	return Matrix;
}
float** ScalarMatrixSubtraction(float**oldMatrix, int row, int col, int Number)
{
	float ** Matrix = Create2DMatrix(row, col);
	Matrix = CopyMatrixData(Matrix, oldMatrix, row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Matrix[j][i] -= Number;
		}
	}
	return Matrix;
}
float**  ScalarMatrixMultiplication(float**oldMatrix, int row, int col, int Number)
{
	float ** Matrix = Create2DMatrix(row, col);
	Matrix = CopyMatrixData(Matrix, oldMatrix, row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Matrix[j][i] *= Number;
		}
	}
	return Matrix;
}
float**  ScalarMatrixDivision(float**oldMatrix, int row, int col, int Number)
{
	float ** Matrix = Create2DMatrix(row, col);
	Matrix = CopyMatrixData(Matrix, oldMatrix, row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Matrix[j][i] /= Number;
		}
	}
	return Matrix;
}
void MatrixTranspose(float**Matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << Matrix[j][i] << " ";
		}
		cout << endl;
	}
}
void MatrixTransposeFile(float**Matrix, int row, int col)
{
	ofstream fout("output_f1.txt", ios::app);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			fout << Matrix[j][i] << " ";
		}
		fout << endl;
	}
	fout.close();
}

float** CreateMatrixFromFile(int& Rows, int& Colums)
{
	char*  FileName = new char[100]{'\0'};
	float** Matrix = nullptr;
	cout << "Enter file name" << endl;
	cin >> FileName;
	Colums = getCol(AddDotTxt(FileName));
	Rows = getRows(AddDotTxt(FileName));
	if (Colums != Rows)cout << "Not Balanced Matrix" << endl;
	Matrix = SetMatrixFromFile(FileName, Matrix, Rows, Colums);
	return Matrix;
}
void DeleteMatrix(float**& Matrix, int row)
{
	for (int i = 0; i < row; i++)
	{
		delete[]Matrix[i];
		Matrix[i] = nullptr;
	}
	Matrix = nullptr;
}
void AdditionofTwoMatrix(float** Matrix1, float**Matrix2, int row, int col, int row2, int col2)
{
	int MaxRow = 0;
	if (row>row2)MaxRow = row;
	else MaxRow = row2;

	int MaxCol = 0;
	if (col > col2)MaxCol = col;
	else MaxCol = col2;

	float** AdditionMatrix = Create2DMatrix(MaxRow, MaxCol);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			AdditionMatrix[i][j] += Matrix1[i][j];
		}
	}


	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			AdditionMatrix[i][j] += Matrix2[i][j];
		}
	}
	DisplayMatrix(AdditionMatrix, MaxRow, MaxCol);
}
void AdditionofTwoMatrixFile(float** Matrix1, float**Matrix2, int row, int col, int row2, int col2)
{
	int MaxRow = 0;
	if (row>row2)MaxRow = row;
	else MaxRow = row2;

	int MaxCol = 0;
	if (col > col2)MaxCol = col;
	else MaxCol = col2;

	float** AdditionMatrix = Create2DMatrix(MaxRow, MaxCol);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			AdditionMatrix[i][j] += Matrix1[i][j];
		}
	}


	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			AdditionMatrix[i][j] += Matrix2[i][j];
		}
	}
	WritingMatrix(AdditionMatrix, MaxRow, MaxCol);
}
void SubtractionofTwoMatrixFile(float** Matrix1, float**Matrix2, int row, int col, int row2, int col2)
{
	int MaxRow = 0;
	if (row>row2)MaxRow = row;
	else MaxRow = row2;

	int MaxCol = 0;
	if (col > col2)MaxCol = col;
	else MaxCol = col2;

	float** AdditionMatrix = Create2DMatrix(MaxRow, MaxCol);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			AdditionMatrix[i][j] += Matrix1[i][j];
		}
	}


	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			AdditionMatrix[i][j] -= Matrix2[i][j];
		}
	}
	WritingMatrix(AdditionMatrix, MaxRow, MaxCol);
}
void SubtractionofTwoMatrix(float** Matrix1, float**Matrix2, int row, int col, int row2, int col2)
{
	int MaxRow = 0;
	if (row>row2)MaxRow = row;
	else MaxRow = row2;

	int MaxCol = 0;
	if (col > col2)MaxCol = col;
	else MaxCol = col2;

	float** AdditionMatrix = Create2DMatrix(MaxRow, MaxCol);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			AdditionMatrix[i][j] += Matrix1[i][j];
		}
	}


	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			AdditionMatrix[i][j] -= Matrix2[i][j];
		}
	}
	DisplayMatrix(AdditionMatrix, MaxRow, MaxCol);
}
float** Create2DMatrix(int row, int col)
{
	float ** Matrix = new float*[row];
	for (int i = 0; i < row; i++)Matrix[i] = new float[col];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)Matrix[i][j] = 0;
	}
	return Matrix;
}
void MultiplicationofTwoMatrix(float** Matrix1, float**Matrix2, int row, int col, int row2, int col2)
{
	float** Result = Create2DMatrix(row, col2);
	if (col != row2)
	{
		cout << "Multiplication not possible" << endl;
		return;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col2; j++) {
			Result[i][j] = 0;
			for (int k = 0; k < col; k++) {
				Result[i][j] += Matrix1[i][k] * Matrix2[k][j];
			}
		}
	}
	cout << "\nResult Matrix" << endl;
	DisplayMatrix(Result, row, col2);
}

void MultiplicationofTwoMatrixFile(float** Matrix1, float**Matrix2, int row, int col, int row2, int col2)
{
	float** Result = Create2DMatrix(row, col2);
	ofstream fout("output_f1.txt", ios::app);
	if (col != row2)
	{
		fout << "Multiplication not possible" << endl;
		return;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col2; j++) {
			Result[i][j] = 0;
			for (int k = 0; k < col; k++) {
				Result[i][j] += Matrix1[i][k] * Matrix2[k][j];
			}
		}
	}
	fout << "\nResult Matrix" << endl;
	fout.close();
	WritingMatrix(Result, row, col2);
}
void Determinant(float** Matrix, int row, int col)
{
	int Determinant = 0;
	if (row != col)
	{
		cout << "Not Possible" << endl;
		return;
	}
	else if (row == 2)
	{
		Determinant = (Matrix[0][0] * Matrix[1][1]) - (Matrix[0][1] * Matrix[1][0]);
	}
	else if (row == 3)
	{
		for (int i = 0; i < row; i++)
		{
			Determinant = ((Matrix[0][0] * ((Matrix[1][1] * Matrix[2][2]) - (Matrix[1][2] * Matrix[2][1])))
				- (Matrix[0][1] * ((Matrix[1][0] * Matrix[2][2]) - (Matrix[1][2] * Matrix[2][0])))
				+ (Matrix[0][2] * ((Matrix[1][0] * Matrix[2][1]) - (Matrix[1][1] * Matrix[2][0]))));
		}
	}
	else
	{
		return;
	}
	cout << "Determinant of the Matrix is " << Determinant << endl;
}
void DeterminantFile(float** Matrix, int row, int col)
{
	ofstream fout("output_f1.txt");
	int Determinant = 0;
	if (row != col)
	{
		fout << "Not Possible" << endl;
		fout.close();
		return;
	}
	else if (row == 2)
	{
		Determinant = (Matrix[0][0] * Matrix[1][1]) - (Matrix[0][1] * Matrix[1][0]);
	}
	else if (row == 3)
	{
		for (int i = 0; i < row; i++)
		{
			Determinant = ((Matrix[0][0] * ((Matrix[1][1] * Matrix[2][2]) - (Matrix[1][2] * Matrix[2][1])))
				- (Matrix[0][1] * ((Matrix[1][0] * Matrix[2][2]) - (Matrix[1][2] * Matrix[2][0])))
				+ (Matrix[0][2] * ((Matrix[1][0] * Matrix[2][1]) - (Matrix[1][1] * Matrix[2][0]))));
		}
	}
	else
	{
		fout.close();
		return;
	}
	fout << "Determinant of the Matrix is " << Determinant << endl;
	fout.close();
}
void InverseofMatrix(float** oldMatrix, int row, int col)
{
	float ** Matrix = Create2DMatrix(row, col);
	Matrix = CopyMatrixData(Matrix, oldMatrix, row, col);
	if (row != col)
	{
		cout << "Not Possible" << endl;
		return;
	}
	else if (row == 2)
	{
		Matrix[0][0] = oldMatrix[1][1];
		Matrix[1][1] = oldMatrix[0][0];
		Matrix[0][1] = -oldMatrix[0][1];
		Matrix[1][0] = -oldMatrix[1][0];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << Matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		return;
	}
}
void InverseofMatrixFile(float** oldMatrix, int row, int col)
{
	float ** Matrix = Create2DMatrix(row, col);
	Matrix = CopyMatrixData(Matrix, oldMatrix, row, col);
	ofstream fout("output_f1.txt", ios::app);
	if (row != col)
	{
		fout << "Not Possible" << endl;
		return;
	}
	else if (row == 2)
	{
		Matrix[0][0] = oldMatrix[1][1];
		Matrix[1][1] = oldMatrix[0][0];
		Matrix[0][1] = -oldMatrix[0][1];
		Matrix[1][0] = -oldMatrix[1][0];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				fout << Matrix[i][j] << " ";
			}
			fout << endl;
		}
	}
	else
	{
		fout.close();
		return;
	}
	fout.close();
}
void DisplayonFileorConsole(bool usingFile, float ** Matrix, int Rows, int Colums, float** NewMatrix)
{
	if (usingFile == false)
	{
		cout << "Old Matrix" << endl;
		DisplayMatrix(Matrix, Rows, Colums);
		cout << "New Matrix" << endl;
		DisplayMatrix(NewMatrix, Rows, Colums);
	}
	else
	{
		ofstream fout("output_f1.txt");

		fout << "Old Matrix" << endl;
		fout.close();
		WritingMatrix(Matrix, Rows, Colums);
		fout.open("output_f1.txt", ios::app);
		fout << "New Matrix" << endl;
		fout.close();
		WritingMatrix(NewMatrix, Rows, Colums);
	}
}