#include <stdio.h>
#include <string.h>
#include <ctype.h>


// helper function to check if a char is a vowel
int is_vowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void to_pig_latin(char *str) {
    // check for empty string
    if (str[0] == '\0') {
        return;
    }

    char first_char = str[0];

    // if starts with vowel, just add "ay" to end
    if (is_vowel(first_char)) {
        strcat(str, "ay");
    // if starts with consonant, move first char to end and add "ay"
    } else {
        size_t len = strlen(str);
        memmove(str, str + 1, len); // shift left by 1
        str[len - 1] = first_char;  // move first char to end
        str[len] = '\0';            // null terminate
        strcat(str, "ay");          // add "ay"
    }   
}

int main() {
    char str[100];

    // get user input
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        perror("fgets");
        return 1;
    }

    // remove newline if present
    str[strcspn(str, "\n")] = '\0';

    to_pig_latin(str);
    printf("Pig Latin: %s\n", str);

    return 0;
}