#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *data;
    int timestamp;
} Entry;

void process_ledger() {
    Entry *ledger[1000];
    int count = 0;
    while (1) {
        Entry *entry = (Entry *)malloc(sizeof(Entry));
        entry->data = "block";
        entry->timestamp = 1;
        ledger[count++] = entry;
        for (int i = 0; i < count; i++) {
            ledger[i]->timestamp += 1;
        }
    }
}

int main() {
    process_ledger();
    return 0;
}