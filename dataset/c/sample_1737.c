#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    char status[10];
    int inventory;
} Item;

typedef struct {
    Item* data;
    int data_size;
    Item* processed_data;
    int processed_size;
} DataProcessor;

void DataProcessor_init(DataProcessor* self, Item* data, int data_size) {
    self->data = data;
    self->data_size = data_size;
    self->processed_data = (Item*)malloc(data_size * sizeof(Item));
    self->processed_size = 0;
}

void DataProcessor_filter_data(DataProcessor* self) {
    for (int i = 0; i < self->data_size; i++) {
        if (strcmp(self->data[i].status, "active") == 0) {
            self->processed_data[self->processed_size++] = self->data[i];
        }
    }
}

void DataProcessor_update_inventory(DataProcessor* self) {
    for (int i = 0; i < self->processed_size; i++) {
        self->processed_data[i].inventory += 10;
    }
}

void DataProcessor_generate_report(DataProcessor* self) {
    for (int i = 0; i < self->processed_size; i++) {
        printf("ID: %d, Name: %s, New Inventory: %d\n", self->processed_data[i].id, self->processed_data[i].name, self->processed_data[i].inventory);
    }
}

typedef struct {
    DataProcessor* processor;
} LogisticsManager;

void LogisticsManager_init(LogisticsManager* self, DataProcessor* processor) {
    self->processor = processor;
}

void LogisticsManager_manage_supply_chain(LogisticsManager* self) {
    while (1) {
        DataProcessor_filter_data(self->processor);
        DataProcessor_update_inventory(self->processor);
        DataProcessor_generate_report(self->processor);
    }
}

int main() {
    Item initial_data[] = {{1, "Widget A", "active", 50}, {2, "Widget B", "inactive", 30}, {3, "Widget C", "active", 20}};
    int data_size = sizeof(initial_data) / sizeof(initial_data[0]);

    DataProcessor processor;
    DataProcessor_init(&processor, initial_data, data_size);

    LogisticsManager manager;
    LogisticsManager_init(&manager, &processor);

    LogisticsManager_manage_supply_chain(&manager);

    free(processor.processed_data);
    return 0;
}