/**
 * 
 * @file subsetsum.c
 * @author Max Base (maxbasecode@gmail.com)
 * @brief Implementation of subset sum problem with backtracking algorithm
 * @version 0.1
 * @date 2022-12-10
 * @copyright Copyright (c) 2022 Max Base
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool promising(int i, int weight, int total, int *numbers, int count, int target_sum)
{
    return (weight + total >= target_sum) && (weight == target_sum || weight + numbers[i + 1] <= target_sum);
}

int **findSolutions(int *numbers, int count, int target_sum)
{
    int total = 0;
    for (int i = 0; i < count; i++)
        total += numbers[i];

    int *solution = (int *)malloc(count * sizeof(int));
    int **solutions = (int **)malloc(count * sizeof(int *));

    int solution_count = 0;

    int i = 0, weight = 0;
    while (1)
    {
        while (i < count && promising(i, weight, total, numbers, count, target_sum))
        {
            weight += numbers[i];
            solution[i] = 1;
            i++;
        }

        if (weight == target_sum)
        {
            solutions[solution_count] = (int *)malloc(count * sizeof(int));
            for (int j = 0; j < count; j++)
                solutions[solution_count][j] = solution[j];
            solution_count++;
        }

        while (i >= 0 && solution[i] != 1)
            i--;

        if (i < 0)
            break;

        solution[i] = 0;
        weight -= numbers[i];
        i++;
    }

    printf("The subset is: ");
    for (int i = 0; i < count; i++)
        if (solution[i] == 1)
            printf("%d ", numbers[i]);
    printf("\n");

    return solutions;
}

int main(int argc, char **argv)
{
    // Enter the number of elements: 5
    // Enter the elements: 1 2 3 4 5
    // Enter the sum: 10
    // The subset is: 1 2 3 4

    int n, sum;
    int *a = (int *)malloc(n * sizeof(int));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the sum: ");
    scanf("%d", &sum);

    int **solutions = findSolutions(a, n, sum);

    return 0;
}
