#include <iostream>
#include <iomanip>

using namespace std;

void create(int** arr, const int row, const int col);
void print(int** arr, const int row, const int col);
int perevirka(int** arr, const int row, const int col, int i, int j);

int main()
{
    int row, col;

    cout << "Enter a number of rows: "; cin >> row;
    cout << "Enter a number of cols: "; cin >> col;   

    int** arr = new int* [row];
    for (int i = 0; i < row; i++)
        arr[i] = new int[col];

    cout << "Enter a matrix: ";
    create(arr, row, col);
    cout << "Matrix" << endl;
    print(arr, row, col);

    int d = perevirka(arr, row, col, 0, 0);
    if (d == 0)
        cout << "False";
    if (d == 1)
        cout << "Yes";


    for (int i = 0; i < row; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}

void create(int** arr, const int row, const int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> arr[i][j];

}
void print(int** arr, const int row, const int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << setw(5) << arr[i][j];
        cout << endl;
    }
}
int perevirka(int** arr, const int row, const int col, int i, int j)
{
    if (i < row - 1)
    {
        if (j < col)
        {
            if (row == col)
            {
                if (arr[i][j] != arr[j][i])
                    return false;
            }
            else
                return false;
            return true;

            return perevirka(arr, row, col, i, j + 1);
        }
        j = 0;
        return perevirka(arr, row, col, i + 1, j);
    }

}
