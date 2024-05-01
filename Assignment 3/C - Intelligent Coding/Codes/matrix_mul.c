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

// Matrix multiplication with i-j-k order
void matrix_multiply_ijk(double **A, double **B, double **C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0.0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_ikj(double **A, double **B, double **C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < n; j++)
            {
                C[i][j] = 0.0;
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_kij(double **A, double **B, double **C, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                C[i][j] = 0.0;
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_kji(double **A, double **B, double **C, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                C[i][j] = 0.0;
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_jki(double **A, double **B, double **C, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                C[i][j] = 0.0;
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_jik(double **A, double **B, double **C, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i][j] = 0.0;
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to measure the execution time of a given function
double measure_time(void (*func)(double **, double **, double **, int), double **A, double **B, double **C, int n)
{
    clock_t start = clock();
    func(A, B, C, n);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Time in milliseconds
}

int main()
{
    FILE *csv_file = fopen("matrix_mul.csv", "w");
    if (csv_file == NULL)
    {
        perror("Could not open file for writing");
        return 1;
    }

    // Write the header row
    fprintf(csv_file, "n,ijk,ikj,kij,kji,jki,jik\n");

    for (int n = 1; n <= 500; n++)
    {
        // Allocate memory for matrices
        double **A = (double **)malloc(n * sizeof(double *));
        double **B = (double **)malloc(n * sizeof(double *));
        double **C = (double **)malloc(n * sizeof(double *));

        for (int i = 0; i < n; i++)
        {
            A[i] = (double *)malloc(n * sizeof(double));
            B[i] = (double *)malloc(n * sizeof(double));
            C[i] = (double *)malloc(n * sizeof(double));
        }

        // Initialize matrices with random values
        initialize_matrix(A, n);
        initialize_matrix(B, n);

        // Measure time for matrix multiplication (i-j-k order)
        double time_taken1 = measure_time(matrix_multiply_ijk, A, B, C, n);
        double time_taken2 = measure_time(matrix_multiply_ikj, A, B, C, n);
        double time_taken3 = measure_time(matrix_multiply_kij, A, B, C, n);
        double time_taken4 = measure_time(matrix_multiply_kji, A, B, C, n);
        double time_taken5 = measure_time(matrix_multiply_jki, A, B, C, n);
        double time_taken6 = measure_time(matrix_multiply_jik, A, B, C, n);
        fprintf(csv_file, "%d,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f\n",
                n,
                time_taken1,
                time_taken2,
                time_taken3,
                time_taken4,
                time_taken5,
                time_taken6);
        // printf("n is : %d\n", n);
        // printf("Time taken for matrix multiplication (i-j-k order) with size %d: %.2f ms\n", n, time_taken1);
        // printf("Time taken for matrix multiplication (i-k-j order) with size %d: %.2f ms\n", n, time_taken2);
        // printf("Time taken for matrix multiplication (k-i-j order) with size %d: %.2f ms\n", n, time_taken3);
        // printf("Time taken for matrix multiplication (k-j-i order) with size %d: %.2f ms\n", n, time_taken4);
        // printf("Time taken for matrix multiplication (j-k-i order) with size %d: %.2f ms\n", n, time_taken5);
        // printf("Time taken for matrix multiplication (j-i-k order) with size %d: %.2f ms\n", n, time_taken6);

        // Free allocated memory
        for (int i = 0; i < n; i++)
        {
            free(A[i]);
            free(B[i]);
            free(C[i]);
        }
        free(A);
        free(B);
        free(C);
    }

    return 0;
}
