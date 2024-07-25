#include <stdio.h>
#include <string.h>
void eliminateCommonSubexpressions(char *input) {
    char tempVar[100];
    char optimizedCode[500];
    int tempVarCount = 1;
    char *ptr, *subexpr;
    optimizedCode[0] = '\0';
    const char *commonSubexpr = "b * c";
    snprintf(tempVar, sizeof(tempVar), "t%d = %s;", tempVarCount++, commonSubexpr);
    strcat(optimizedCode, tempVar);
    strcat(optimizedCode, "\n");
    ptr = input;
    while ((subexpr = strstr(ptr, commonSubexpr)) != NULL) {
        strncat(optimizedCode, ptr, subexpr - ptr);
        strcat(optimizedCode, "t1");
        ptr = subexpr + strlen(commonSubexpr);
    }
    strcat(optimizedCode, ptr);
    printf("Optimized Code:\n%s\n", optimizedCode);
}
int main() {
    char code[500];
    printf("Enter the code (end with ';'):\n");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = 0;
    printf("Original Code:\n%s\n", code);
    eliminateCommonSubexpressions(code);
    return 0;
}

