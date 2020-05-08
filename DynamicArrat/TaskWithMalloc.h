//
//  TaskWithMalloc.h
//  DynamicArrat
//
//  Created by Дмитрий Марченков on 21.04.2020.
//  Copyright © 2020 Дмитрий Марченков. All rights reserved.
//

#ifndef TaskWithMalloc_h
#define TaskWithMalloc_h

#include <stdio.h>
#include <malloc/malloc.h>
using namespace std;

void dynamicArrayWithMalloc () {
    int *arrayPointer;
    int rows, columns;
    int *sumOfMinAndMax,
    min = INT_MAX,
    max = INT_MIN;
    
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> columns;
    
    arrayPointer   = (int*)malloc(rows * columns * sizeof(int));
    sumOfMinAndMax = (int*)malloc(rows * sizeof(int));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("a[%d][%d] = ", i, j);
            cin >> arrayPointer[i * columns + j];
            
            if (arrayPointer[i * columns + j] > max) {
                max = arrayPointer[i * columns + j];
            }
            
            if (arrayPointer[i * columns + j] < min) {
                min = arrayPointer[i * columns + j];
            }
        }
        sumOfMinAndMax[i] = max + min;
        min = INT_MAX;
        max = INT_MIN;
    }
    
    
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << arrayPointer[i * columns + j] << " ";
            
        }
        cout << "Сумма минимум и максимума = " << sumOfMinAndMax[i];
        cout << endl;
    }
    
    free(arrayPointer);
    free(sumOfMinAndMax);
    getchar();
}


void partTwoMalloc () {
    int *matrix;
    int countOfNumbers[9];
    int newElement;
    int column = 9;
    int count  = 0;
    char choise;
    bool sameNumber = false;
    
    matrix = (int*)malloc(count * sizeof(int*));
    
    for (int i = 0; i < 10; i++) {
        countOfNumbers[i] = 0;
        matrix[i] = NULL;
    }
    

    do {
        cout << "Введите число ";
        cin >> newElement;
        int lastNumber = abs(newElement % 10);
        
        for (int i = 0; i < countOfNumbers[lastNumber]; i++) {
            if (matrix[lastNumber * column + i] == newElement) {
                cout << "Повторяющийся элемент" << endl;
                sameNumber = true;
            }
        }
        
        if (!sameNumber) {
            matrix = (int*)realloc(matrix, count * sizeof(int));
            matrix[lastNumber * column + countOfNumbers[lastNumber]] = newElement;
            countOfNumbers[lastNumber] += 1;
            count += 1;
        }
        
        sameNumber = false;
        getchar();
        cout << "Next (y/n)? ";
        choise = getchar();
    } while (choise == 'y');

    for (int i = 0; i < 10; i++) {
        cout << i << ") ";
        for (int j = 0; j < countOfNumbers[i]; j++) {
            cout << matrix[i * column + j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    
    free(matrix);
}


#endif /* TaskWithMalloc_h */
