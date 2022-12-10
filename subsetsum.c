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

void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum){
//    total_nodes++;
    if (target_sum == sum) {
        for (int i = 0 ; i < t_size; i++)
            printf("%d ", t[i]);
        printf("\n");
        subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
        return;
    }
    else {
        for (int i = ite; i < s_size; i++) {
            t[t_size] = s[i];
            subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
        }
    }
}

// bool promising(int i, int weight, int total, int *numbers, int count, int target_sum)
// {
//     return (weight + total >= target_sum) && (weight == target_sum || weight + numbers[i + 1] <= target_sum);
// }

// Solution *findSolutions(int *numbers, int count, int target_sum)
// {
//     Solution *solutions = (Solution *)malloc(sizeof(Solution));
//     solutions->solution = (int **)malloc(sizeof(int *) * count);
//     solutions->solution_count = 0;

//     printf("Target sum: %d\n", target_sum);
//     printf("Number of numbers: %d (", count);
//     for (int i = 0; i < count; i++)
//         printf(i == count - 1 ? "%d" : "%d ", numbers[i]);
//     printf(")\n");

//     // Can [-2, -1, 0, 1, 2] sum to 0? True
//     // [-2, -1, 0, 1, 2] sums to 0
//     // [-2, -1, 1, 2] sums to 0
//     // [-2, 0, 2] sums to 0
//     // [-2, 2] sums to 0
//     // [-1, 0, 1] sums to 0
//     // [-1, 1] sums to 0
//     // [0] sums to 0

//     int *x = (int *)malloc(sizeof(int) * count);
//     int total = 0;
//     for (int i = 0; i < count; i++)
//         total += numbers[i];

//     int i = 0, weight = 0;
//     while (i >= 0) {
//         x[i] += 1;
//         while (x[i] <= 1 && !promising(i, weight, total, numbers, count, target_sum))
//             x[i] += 1;
//         if (x[i] == 2) {
//             i--;
//             total -= numbers[i + 1];
//         } else {
//             weight += numbers[i];
//             if (weight == target_sum) {
//                 solutions->solution[solutions->solution_count] = (int *)malloc(sizeof(int) * count);
//                 for (int j = 0; j <= i; j++)
//                     solutions->solution[solutions->solution_count][j] = x[j];
//                 solutions->solution_count++;
//             } else {
//                 i++;
//                 x[i] = 0;
//                 total += numbers[i];
//             }
//         }
//     }

//     return solutions;
// }

int main(int argc, char **argv)
{
    // Enter the number of elements: 5
    // Enter the elements: 1 2 3 4 5
    // Enter the sum: 10
    // The subset is: 1 2 3 4

    // Enter the number of elements: 5
    // Enter the elements: -2
    // -1
    // 0
    // 1
    // 2
    // Enter the sum: 0

    int n, target_sum;

    n = 5;
//    printf("Enter the number of elements: ");
//    scanf("%d", &n);

    int *set = (int *)malloc(n * sizeof(int));
    set[0] = -2;
    set[1] = -1;
    set[2] = 0;
    set[3] = 1;
    set[4] = 2;
//    printf("Enter the elements: ");
//    for (int i = 0; i < n; i++)
//        scanf("%d", &set[i]);

    target_sum = 0;
//    printf("Enter the sum: ");
//    scanf("%d", &target_sum);

    printf("Finding solutions...\n");
    // Solution *solutions = findSolutions(set, n, sum);

    // printf("Number of solutions: %d\n", solutions->solution_count);

    // printf("The subsets are:\n");
    // for (int i = 0; i < solutions->solution_count; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (solutions->solution[i][j] == 1)
    //             printf("%d ", set[j]);
    //     }
    //     printf("\n");
    // }

    int* tuplet_vector = (int*)malloc(n * sizeof(int));
    subset_sum(set, tuplet_vector, n, 0, 0, 0, target_sum);
    free(tuplet_vector);

    return 0;
}
