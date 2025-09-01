#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

static int copy_file_contents(FILE *source, FILE *dest) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        if (fwrite(buffer, 1, bytes_read, dest) != bytes_read) {
            perror("Error writing to output file");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int concatenate_files(const char *input1, const char *input2, const char *output) {
    FILE *file1 = NULL;
    FILE *file2 = NULL;
    FILE *file3 = NULL;
    int status = EXIT_SUCCESS;

    // Open first input file
    file1 = fopen(input1, "r");
    if (file1 == NULL) {
        perror("Error opening first input file");
        return EXIT_FAILURE;
    }

    // Open second input file
    file2 = fopen(input2, "r");
    if (file2 == NULL) {
        perror("Error opening second input file");
        fclose(file1);
        return EXIT_FAILURE;
    }

    // Open output file
    file3 = fopen(output, "w");
    if (file3 == NULL) {
        perror("Error opening output file");
        fclose(file1);
        fclose(file2);
        return EXIT_FAILURE;
    }

    // Copy contents of both files
    if ((status = copy_file_contents(file1, file3)) == EXIT_SUCCESS) {
        status = copy_file_contents(file2, file3);
    }

    // Cleanup
    fclose(file1);
    fclose(file2);
    fclose(file3);

    return status;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <file1> <file2> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    return concatenate_files(argv[1], argv[2], argv[3]);
}

// make run ARGS="input1.txt input2.txt output.txt"