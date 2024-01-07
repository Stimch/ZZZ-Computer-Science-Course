#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t** Matrix;

const int32_t N = 4;
const int32_t M = 4;

Matrix CreateMatrix(int lines) {
    Matrix matrix = (int32_t**)malloc(lines * sizeof(int32_t*));
    for (int i = 0; i < lines; ++i) {
        matrix[i] = (int32_t*)malloc(lines * sizeof(int32_t));
    }
    return matrix;
}

Matrix FillMatrix(Matrix matrix, int32_t lines, int32_t columns) {
    for (int32_t i = 0; i < lines; ++i) {
        for (int32_t j = 0; j < columns; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

void PrintMatrix(Matrix matrix, int32_t lines, int32_t columns) {
    for (int32_t i = 0; i < lines; ++i) {
        for (int32_t j = 0; j < columns; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int32_t GoThroughMatrix(Matrix matrix, int32_t* a, int32_t swing, int32_t lines, int32_t columns, int32_t steps) {
    int32_t k = 1;
    int32_t direction = 0;  // переменная для направления движения по матрице
    for (int x = 0; x < swing; x++) {
        for (int y = 0; y < 2; y++) {
            if (direction == 0) {  // direction = 0 => двигаемся вправо
                for (int e = 1; e < steps + 1; e++) {
                    columns += 1;  // увеличиваем columns на 1, т.к. идём вправо
                    *(a + k) = matrix[lines][columns];
                    k += 1;
                }
                direction += 1;
            } else if (direction == 1) {  // direction = 1 => двигаемся вниз
                for (int e = 1; e < steps + 1; e++) {
                    lines += 1;  // увеличиваем lines на 1, т.к. идём вниз
                    *(a + k) = matrix[lines][columns];
                    k += 1;
                }
                steps += 1;
                direction += 1;
            } else if (direction == 2) {  // direction = 2 => двигаемся влево
                for (int e = 1; e < steps + 1; e++) {
                    columns -= 1;  // уменьшаем columns на 1, т.к. идём влево
                    *(a + k) = matrix[lines][columns];
                    k += 1;
                }
                direction += 1;
            } else if (direction == 3) {  // direction = 3 => двигаемся вверх
                for (int e = 1; e < steps + 1; e++) {
                    lines -= 1;  // уменьшаем lines на 1, т.к. идём вверх
                    *(a + k) = matrix[lines][columns];
                    k += 1;
                }
                steps += 1;
                direction = 0;  // обнуляем direction, т.к. следующее движение должно быть вправо
            }
        }
    }
    for (int i = 0; i < swing; i++) {  // цикл для движения влево по последней строке
        columns -= 1;
        *(a + k) = matrix[lines][columns];
        k += 1;
    }
}

int Task() {
    int32_t lines = N;
    int32_t columns = M;
    int32_t size = lines * columns;
    Matrix matrix = CreateMatrix(lines);
    matrix = FillMatrix(matrix, lines, columns);
    printf("The Original Matrix:\n");
    PrintMatrix(matrix, lines, columns);
    int32_t a[N * M];  // массив для хранения результата
    int32_t k = 1;
    int32_t steps = 1;
    lines = (lines / 2) - 1;  // уменьшаем значение переменной для определения точки старта
    columns = (columns / 2) - 1;  // уменьшаем значение переменной для определения точки старта
    int32_t swing = (((columns + 1) * 2) - 1);  // посчитал эту переменную для определния кол-ва "махов"
    *(a) = matrix[lines][columns];
    printf("The Result:\n");
    GoThroughMatrix(matrix, a, swing, lines, columns, steps);
    for (int32_t i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
    for (size_t i = 0; i < N; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}