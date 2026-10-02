#include <stdio.h>
#include <stdbool.h>

bool validate_node_status(const char* status, const char* consensus) {
    return (status[0] == 'a' && status[1] == 'c' && status[2] == 't' && status[3] == 'i' && status[4] == 'v' && status[5] == 'e' && status[6] == '\0') &&
           (consensus[0] == 'r' && consensus[1] == 'e' && consensus[2] == 'a' && consensus[3] == 'c' && consensus[4] == 'h' && consensus[5] == 'e' && consensus[6] == 'd' && consensus[7] == '\0');
}

bool process_ledger(const void* ledger, int threshold, int ledger_size) {
    for (int i = 0; i < ledger_size; i++) {
        const char* status = ((const char* const*)ledger)[i*3];
        const char* consensus = ((const char* const*)ledger)[i*3 + 1];
        int transactions = *(int*)((const char* const*)ledger)[i*3 + 2];
        if (!validate_node_status(status, consensus)) {
            return false;
        }
        if (transactions > threshold) {
            return false;
        }
    }
    return true;
}

int main() {
    const char* ledger_data[] = {
        "active", "reached", (char*)&(int){100},
        "active", "reached", (char*)&(int){200},
        "active", "reached", (char*)&(int){300}
    };
    int threshold_value = 250;
    bool result = process_ledger(ledger_data, threshold_value, 3);
    printf("%d\n", result);
    return 0;
}