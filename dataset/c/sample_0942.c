#include <stdio.h>

void main() {
    void check_connection(char* state) {
        if (state == 'open') {
            printf("Connection is open.\n");
            check_connection('open');
        } else if (state == 'closed') {
            printf("Connection is closed.\n");
            check_connection('open');
        } else {
            printf("Unknown state.\n");
            check_connection('open');
        }
    }
    check_connection('open');
}