#include <stdio.h>
#include <stdlib.h>

int main() {
    // buffer for getline
    char *line = NULL;
    // getline buffer size
    size_t len = 0;
    // number of characters read by getline
    ssize_t read;

    // get first number
    printf("%s", "Enter first number: ");
    read = getline(&line, &len, stdin);
    if (read == -1) {
        perror("getline");
        free(line);
        return EXIT_FAILURE;
    }
    int num1 = atoi(line);
    
    // get second number
    printf("%s", "Enter second number: ");
    read = getline(&line, &len, stdin);
    if (read == -1) {
        perror("getline");
        free(line);
        return EXIT_FAILURE;
    }
    int num2 = atoi(line);

    // print sum
    printf("Sum: %d\n", num1 + num2);

    free(line);
    return EXIT_SUCCESS;
}