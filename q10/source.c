#include <stdio.h>

// Function to check if the given character matches the expected character
int match(char expected, char input) {
    if (expected == input) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the input string follows the grammar rule 'E -> T'
int E(char input[]) {
    if (T(input)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the input string follows the grammar rule 'T -> F'
int T(char input[]) {
    if (F(input)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the input string follows the grammar rule 'F -> (E)'
int F(char input[]) {
    if (match(input[0], '(') && E(input + 1) && match(input[strlen(input) - 1], ')')) {
        return 1;
    } else if (match(input[0], 'a')) {
        return 1;
    } else if (match(input[0], 'b')) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input[100];

    printf("Enter the input string: ");
    scanf("%s", input);

    if (E(input)) {
        printf("The input string is valid according to the grammar.\n");
    } else {
        printf("The input string is not valid according to the grammar.\n");
    }

    return 0;
}
