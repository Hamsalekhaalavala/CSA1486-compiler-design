#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void generateThreeAddressCode(const char *expression) {
    char stack[100][10];
    int top = -1;
    char tempVar = 't'; 
    printf("Three-Address Code:\n");
    for (int i = 0; expression[i]; i++) {
        if (isspace(expression[i])) continue;

        if (isalnum(expression[i]) || expression[i] == '(' || expression[i] == ')') {
            if (isalnum(expression[i])) {
                char operand[10];
                snprintf(operand, sizeof(operand), "%c", expression[i]);
                strcpy(stack[++top], operand);
            }
        } else if (expression[i] == '+' || expression[i] == '-' ||
                   expression[i] == '*' || expression[i] == '/') {
            char operand2[10], operand1[10];
            strcpy(operand2, stack[top--]);
            strcpy(operand1, stack[top--]);
            char temp[10];
            snprintf(temp, sizeof(temp), "%c%d", tempVar, top + 1);
            printf("%s = %s %c %s\n", temp, operand1, expression[i], operand2);
            strcpy(stack[++top], temp);
            tempVar++;
        }
    }
}
int main() {
    char expression[100];
    printf("Enter an arithmetic expression (e.g., a+b*(c-d)/e):\n");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0;
    generateThreeAddressCode(expression);
    return 0;
}

