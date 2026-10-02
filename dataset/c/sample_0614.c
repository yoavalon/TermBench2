#include <stdio.h>
#include <stdbool.h>

bool validate_ledger(int data[], int index) {
    if (index >= 4) {
        return true;
    }
    if (data[index] != data[index + 1]) {
        return false;
    }
    return validate_ledger(data, index + 1);
}

int main() {
    int ledger_data[] = {1, 1, 1, 1, 1};
    printf("%d\n", validate_ledger(ledger_data, 0));
    return 0;
}