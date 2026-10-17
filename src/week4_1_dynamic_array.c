/*
 * Name: Naim
 * Surname: Khuduzade
 * Student ID: 251ADB072
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr); // Yaddaşı azad edirik
            return 1;
        }
        sum += arr[i];
    }

    printf("Sum = %d\n", sum);
    // Ortalamanı hesablayarkən tam ədəd (int) bölməsinin qarşısını almaq üçün cast edirik
    printf("Average = %.2f\n", (float)sum / n);

    free(arr); // Yaddaş sızmasının (memory leak) qarşısını alırıq
    return 0;
}