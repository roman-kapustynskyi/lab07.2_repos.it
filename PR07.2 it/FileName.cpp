#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int CalcSumMinEvenCols(int** a, const int k, const int n);
int FindMinInColumn(int** a, const int k, int j);

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int FindMinInColumn(int** a, const int k, int j)
{
    int min = a[0][j];
    for (int i = 1; i < k; i++) {
        if (a[i][j] < min) {
            min = a[i][j];
        }
    }
    return min;
}

int CalcSumMinEvenCols(int** a, const int k, const int n)
{
    int s = 0;
    for (int j = 0; j < n; j++) {
        if (j % 2 != 0) {
            int currentMin = FindMinInColumn(a, k, j);
            s += currentMin;
        }
    }
    return s;
}

int main()
{
    srand((unsigned)time(NULL));
    int Low = -10;
    int High = 50;

    int k, n;
    cout << "k = "; cin >> k;
    cout << endl;
    cout << "n = "; cin >> n;
    cout << endl;

    int** a = new int* [k];
    for (int i = 0; i < k; i++) {
        a[i] = new int[n];
    }

    Create(a, k, n, Low, High);
    Print(a, k, n);

    int result = CalcSumMinEvenCols(a, k, n);

    cout << "CalcSumMinEvenCols = " << result << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}