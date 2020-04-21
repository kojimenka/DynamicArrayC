//
//  TaskWithPointer.h
//  DynamicArrat
//
//  Created by Дмитрий Марченков on 21.04.2020.
//  Copyright © 2020 Дмитрий Марченков. All rights reserved.
//

#ifndef TaskWithPointer_h
#define TaskWithPointer_h

#include <stdio.h>
#include <malloc/malloc.h>
using namespace std;

void dynamicArrayWithPointer () {
    int **arrayOfPointer;
    int *sumOfMinAndMax;
    int rows, columns,
    min = INT_MAX,
    max = INT_MIN;
    
    cout << "Введите количество строк: ";
    cin >> rows;
    
    cout << "Введите количество столбцов: ";
    cin >> columns;
    
    arrayOfPointer = (int**)malloc(rows * sizeof(int*));
    sumOfMinAndMax = (int*)malloc(rows * sizeof(int));
    
    for (int i = 0; i < rows; i++) {
        arrayOfPointer[i] = (int*)malloc(columns * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("a[%d][%d] = ", i, j);
            cin >> arrayOfPointer[i][j];
            
            if (arrayOfPointer[i][j] > max) {
                max = arrayOfPointer[i][j];
            }
            
            if (arrayOfPointer[i][j] < min) {
                min = arrayOfPointer[i][j];
            }
        }
        sumOfMinAndMax[i] = max + min;
        min = INT_MAX;
        max = INT_MIN;
    }

    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << arrayOfPointer[i][j] << "  ";
        }
        cout << "Сумма минимум и максимума = " << sumOfMinAndMax[i];
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        free(arrayOfPointer[i]);
    }
    
    free(arrayOfPointer);
    free(sumOfMinAndMax);
}

void partTwoWithPointer () {
    int **matrix;
    int countOfNumbers[9];
    int newElement;
    char choise;
    bool sameNumber = false;
    
    matrix = (int**)malloc(9 * sizeof(int*));
    
    for (int i = 0; i < 10; i++) {
        countOfNumbers[i] = 0;
        matrix[i] = NULL;
    }
    
    do {
        cout << "Введите число ";
        cin >> newElement;
        int lastNumber = abs(newElement % 10);
        
        for (int i = 0; i < countOfNumbers[lastNumber]; i++) {
            if (matrix[lastNumber][i] == newElement) {
                cout << "Повторяющийся элемент" << endl;
                sameNumber = true;
            }
        }

        if (sameNumber == false) {
            matrix[lastNumber] = (int*)realloc(matrix[lastNumber], (countOfNumbers[lastNumber]) * sizeof(int));
            matrix[lastNumber][countOfNumbers[lastNumber]] = newElement;
            countOfNumbers[lastNumber] += 1;
        }
        
        sameNumber = false;
        getchar();
        cout << "Next (y/n)? ";
        choise = getchar();
    } while (choise == 'y');
    
    for (int i = 0; i < 10; i++) {
        cout << i << ") ";
        for (int j = 0; j < countOfNumbers[i]; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    
    for (int i = 0; i < 10; i++) {
        free(matrix[i]);
    }
    
    free(matrix);
}

#endif /* TaskWithPointer_h */
