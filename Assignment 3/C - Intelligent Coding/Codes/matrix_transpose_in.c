#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize a square matrix with random values
void initialize_matrix(double **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = ((double)rand() / RAND_MAX) * 10.0; // Random value between 0 and 10
        }
    }
}

// Function to transpose a square matrix in place with (i, j) loop order
void transpose_matrix_inplace_ij(double **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

// Function to transpose a square matrix in place with (j, i) loop order
void transpose_matrix_inplace_ji(double **matrix, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = j + 1; i < n; i++)
        {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

// Function to measure the execution time of a given function
double measure_time(void (*func)(double **, int), double **matrix, int n)
{
    clock_t start = clock();
    func(matrix, n);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Time in milliseconds
}

int main()
{
    FILE *csv_file = fopen("matrix_transpose_in.csv", "a"); // 'w' to create a new file
    if (csv_file == NULL)
    {
        perror("Could not open file for writing");
        return 1;
    }

    // Write the header row
    // fprintf(csv_file, "n,ij,ji\n");

    for (int n = 2001; n <= 4100; n++)
    {
        // Allocate memory for the square matrix
        double **matrix = (double **)malloc(n * sizeof(double *));
        for (int i = 0; i < n; i++)
        {
            matrix[i] = (double *)malloc(n * sizeof(double));
        }

        // Initialize the matrix with random values
        initialize_matrix(matrix, n);

        // Measure transpose times for in-place (ij and ji loop orders)
        double transpose_time_ij = measure_time(transpose_matrix_inplace_ij, matrix, n);
        double transpose_time_ji = measure_time(transpose_matrix_inplace_ji, matrix, n);
        // printf("%.2f, %.2f", transpose_time_ij, transpose_time_ji);

        // Write results to CSV
        fprintf(csv_file, "%d,%.2f,%.2f\n", n, transpose_time_ij, transpose_time_ji);

        // Free allocated memory
        for (int i = 0; i < n; i++)
        {
            free(matrix[i]);
        }
        free(matrix);
    }

    fclose(csv_file);

    return 0;
}
