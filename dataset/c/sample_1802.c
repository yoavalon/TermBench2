#include <stdio.h>
#include <string.h>
#include <math.h>

char* check_ast_semantics(double node) {
    static char result[100];
    sprintf(result, "Float precision: %.15g", node);
    return result;
}

int main() {
    double data[] = {1.0, 2.0, 3.141592653589793, 1e-300, 1e+300};
    char* result;
    for (int i = 0; i < 5; i++) {
        result = check_ast_semantics(data[i]);
        printf("%s\n", result);
    }
    return 0;
}