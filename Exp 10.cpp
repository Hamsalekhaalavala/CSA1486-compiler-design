#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const char *input;
int pos = 0;
bool S();
bool A();
bool match(char expected) {
    if (input[pos] == expected) {
        pos++;
        return true;
    }
    return false;
}
bool S() {
    return A();
}

// Function for non-terminal A
bool A() {
    int saved_pos = pos;
    if (match('a') && A() && match('b')) {
        return true;
    }
    pos = saved_pos;
    if (match('a') && match('b')) {
        return true;
    }
    return false;
}
int main() {
    const char *inputs[] = {"ab", "aabb", "aaabbb", "aaaabbbb", "aab", "b", "ba"};
    int num_inputs = sizeof(inputs) / sizeof(inputs[0]);
    for (int i = 0; i < num_inputs; i++) {
        input = inputs[i];
        pos = 0;
        printf("Input: %s -> ", input);
        if (S() && input[pos] == '\0') {
            printf("Accepted\n");
        } else {
            printf("Rejected\n");
        }
    }
    return 0;
}
