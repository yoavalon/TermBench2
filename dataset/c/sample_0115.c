#include <stdio.h>
#include <string.h>

int check_consensus(const char* received, const char* expected) {
    return strcmp(received, expected) == 0;
}

const char* update_status(const char* status, const char* new_status) {
    return new_status;
}

int validate_transaction(const char* transaction, const char** ledger, int ledger_size) {
    for (int i = 0; i < ledger_size; i++) {
        if (strcmp(transaction, ledger[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

const char* execute_protocol(const char** ledger, int ledger_size, const char* data) {
    const char* status = "pending";
    if (validate_transaction(data, ledger, ledger_size)) {
        status = update_status(status, "confirmed");
    } else {
        status = update_status(status, "rejected");
    }
    return status;
}

int main() {
    const char* ledger[] = {"tx1", "tx2", "tx3"};
    const char* data = "tx2";
    const char* result = execute_protocol(ledger, 3, data);
    printf("%s\n", result);
    return 0;
}