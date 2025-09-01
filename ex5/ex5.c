#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create 2D array
float** create_2d_array(int rows, int cols) {
    float** array = malloc(rows * sizeof(float*));
    if (array == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < rows; i++) {
        array[i] = malloc(cols * sizeof(float));
        if (array[i] == NULL) {
            // Clean up previously allocated memory
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }
    return array;
}

// Function to free 2D array
void free_2d_array(float** array, int rows) {
    if (array == NULL) return;
    
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}

int main() {
    int m, n;
    
    // Get dimensions from user
    printf("Enter number of rows (m): ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        fprintf(stderr, "Invalid input for rows\n");
        return EXIT_FAILURE;
    }
    
    printf("Enter number of columns (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid input for columns\n");
        return EXIT_FAILURE;
    }
    
    // Seed random number generator
    srand(time(NULL));
    
    // Create array
    float** array = create_2d_array(m, n);
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    
    // Fill array with random numbers
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = (float)rand() / RAND_MAX;
        }
    }
    
    // Print array
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.4f ", array[i][j]);
        }
        printf("\n");
    }
    
    // Free memory
    free_2d_array(array, m);
    return EXIT_SUCCESS;
}