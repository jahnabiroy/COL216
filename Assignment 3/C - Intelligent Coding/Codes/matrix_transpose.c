#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize a matrix with random values
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

// Function to transpose a matrix with (i, j) loop order
void transpose_matrix_ij(double **matrix, double **transposed, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transposed[j][i] = matrix[i][j]; // Transpose operation
        }
    }
}

// Function to transpose a matrix with (j, i) loop order
void transpose_matrix_ji(double **matrix, double **transposed, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            transposed[j][i] = matrix[i][j]; // Transpose operation
        }
    }
}

// Function to measure the execution time of a given function
double measure_time(void (*func)(double **, double **, int), double **A, double **B, int n)
{
    clock_t start = clock();
    func(A, B, n);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Time in milliseconds
}

int main()
{
    FILE *csv_file = fopen("matrix_transpose.csv", "a");
    if (csv_file == NULL)
    {
        perror("Could not open file for writing");
        return 1;
    }

    // Write the header row
    fprintf(csv_file, "n,ij,ji\n");

    for (int n = 5142; n <= 6000; n++)
    {
        // Allocate memory for the original matrix and the transposed matrix
        double **matrix = (double **)malloc(n * sizeof(double *));
        double **transposed = (double **)malloc(n * sizeof(double *));

        for (int i = 0; i < n; i++)
        {
            matrix[i] = (double *)malloc(n * sizeof(double));
            transposed[i] = (double *)malloc(n * sizeof(double));
        }

        // Initialize the original matrix with random values
        initialize_matrix(matrix, n);

        // Measure transpose times for both loop orders
        double transpose_time_ij = measure_time(transpose_matrix_ij, matrix, transposed, n);
        double transpose_time_ji = measure_time(transpose_matrix_ji, matrix, transposed, n);

        // Write results to CSV: one line per `n` with both times
        fprintf(csv_file, "%d,%.2f,%.2f\n", n, transpose_time_ij, transpose_time_ji);

        // Free allocated memory
        for (int i = 0; i < n; i++)
        {
            free(matrix[i]);
            free(transposed[i]);
        }
        free(matrix);
        free(transposed);
    }

    fclose(csv_file);

    return 0;
}
