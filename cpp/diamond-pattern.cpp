// ZAIN AKBAR RIZKIA 202531091

#include <iostream>
using namespace std;

int main()
{
    int rows = 3;
    int cols = 5;

    // i*5 + j + 1
    int arr_I[3][5] = { 0 };
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                arr_I[i][j] = (i * cols) + j + 1;
            }
        }
    }

    cout << "01-I:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr_I[i][j] == 0)
                cout << "   ";
            else if (arr_I[i][j] < 10)
                cout << " " << arr_I[i][j] << " ";
            else
                cout << arr_I[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // bertambah setiap cell valid
    int arr_J[3][5] = { 0 };
    int counter_j = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                arr_J[i][j] = counter_j++;
            }
        }
    }

    cout << "01-J:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr_J[i][j] == 0)
                cout << "   ";
            else if (arr_J[i][j] < 10)
                cout << " " << arr_J[i][j] << " ";
            else
                cout << arr_J[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // full grid
    int arr_K[3][5] = { 0 };
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr_K[i][j] = (j * rows) + i + 1;
        }
    }

    cout << "01-K:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr_K[i][j] < 10)
                cout << " " << arr_K[i][j] << " ";
            else
                cout << arr_K[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // mirip b tetapi setengah
    int arr_L[3][5] = { 0 };
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j >= i) {
                arr_L[i][j] = (j * rows) + i + 1;
            }
        }
    }

    cout << "01-L:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr_L[i][j] == 0)
                cout << "   ";
            else if (arr_L[i][j] < 10)
                cout << " " << arr_L[i][j] << " ";
            else
                cout << arr_L[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
