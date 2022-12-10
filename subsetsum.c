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

typedef struct {
    int **solution;
    int solution_count;
} Solution;

bool promising(int i, int weight, int total, int *numbers, int count, int target_sum)
{
    return (weight + total >= target_sum) && (weight == target_sum || weight + numbers[i + 1] <= target_sum);
}

Solution *findSolutions(int *numbers, int count, int target_sum)
{
    Solution *solutions = (Solution *)malloc(sizeof(Solution));
    solutions->solution = (int **)malloc(sizeof(int *) * count);
    solutions->solution_count = 0;

    int *solution = (int *)malloc(sizeof(int) * count);
    int total = 0;
    for (int i = 0; i < count; i++)
        total += numbers[i];
    
    int weight = 0;
    int i = 0;
    while (i >= 0)
    {
        if (promising(i, weight, total, numbers, count, target_sum))
        {
            weight += numbers[i];
            solution[i] = 1;
            if (weight == target_sum)
            {
                solutions->solution[solutions->solution_count] = (int *)malloc(sizeof(int) * count);
                for (int j = 0; j < count; j++)
                    solutions->solution[solutions->solution_count][j] = solution[j];
                solutions->solution_count++;
            }
            i++;
        }
        else
        {
            solution[i] = 0;
            i--;
        }
    }

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

    Solution *solutions = findSolutions(a, n, sum);

    printf("The subset is: ");
    for (int i = 0; i < solutions->solution_count; i++) {
        for (int j = 0; j < n; j++) {
            if (solutions->solution[i][j] == 1)
                printf("%d ", a[j]);
        }
        printf("\n");
    }


    return 0;
}
