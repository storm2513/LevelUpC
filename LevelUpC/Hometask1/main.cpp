//  Created by Максим Шилов, assisted by Анастасия Бебех on 24.10.16.
//  Copyright © 2016 Максим Шилов. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int i, j;
    cout << "Укажи размер матрицы A. Количество строк: ";
    cin >> i;
    cout << "Отлично, теперь введи количество столбцов: ";
    cin >> j;
    int m;
    cout << "Введи количество столбцов матрицы B: ";
    cin >> m;
    double a[i][j];
    double b[j][m];
    double c[i][m];
    cout << "Введи элементы матрицы A: " << endl;
    for (int ind = 0; ind < i; ind++){
        for (int jind = 0; jind < j; jind++){
            cin >> a[ind][jind];
        }
    }
    cout << "Матрица A: " << endl;
    for (int ind = 0; ind < i; ind++){
        for (int jind = 0; jind < j; jind++){
            cout << a[ind][jind] << "  ";
        }
        cout << endl;
    }
    cout << "Введи элементы матрицы B: " << endl;
    for (int jind = 0; jind < i; jind++){
        for (int mind = 0; mind < j; mind++){
            cin >> b[jind][mind];
        }
    }
    cout << "Матрица B: " << endl;
    for (int jind = 0; jind < j; jind++){
        for (int mind = 0; mind < m; mind++){
            cout << b[jind][mind] << "  ";
        }
        cout << endl;
    }
    
    for (int mind = 0; mind < m; mind++){
        for (int ind = 0; ind < i; ind++){
            c[ind][mind] = 0;
            for (int in = 0; in < m; in++){
                c[ind][mind] += a[ind][in] * b[in][mind];
            }
        }
    }
    cout << "Матрица C: " << endl;
    for (int jind = 0; jind < i; jind++){
        for (int mind = 0; mind < m; mind++){
            cout << c[jind][mind] << "  ";
        }
        cout << endl;
    }
    cout << "Изменённая матрица C: " << endl;
    for (int jind = 0; jind < i; jind++){
        for (int mind = 0; mind < m; mind++){
            c[jind][mind] = (int(c[jind][mind]) % 2 == 0) ? 0 : 1;
            cout << c[jind][mind] << "  ";
        }
        cout << endl;
    }
    
    return 0;
}
