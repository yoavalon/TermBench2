#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *status;
    char *category;
    char *region;
    int quantity;
    float cost;
    char *priority;
    int reorder;
} Item;

typedef struct {
    Item **data;
    int size;
} DataProcessor;

typedef struct {
    DataProcessor *processor;
} DataMutator;

typedef struct {
    DataMutator *mutator;
} DataAnalyzer;

typedef struct {
    char *region;
    float total_cost;
    int item_count;
} RegionAnalysis;

void DataProcessor_init(DataProcessor *self, Item **data, int size) {
    self->data = data;
    self->size = size;
}

Item** DataProcessor_process_data(DataProcessor *self) {
    Item **transformed_data = (Item**)malloc(sizeof(Item*) * self->size);
    int transformed_count = 0;
    for (int i = 0; i < self->size; i++) {
        Item *item = self->data[i];
        if (strcmp(item->status, "active") == 0) {
            Item *modified_item = (Item*)malloc(sizeof(Item));
            modified_item->status = item->status;
            modified_item->category = item->category;
            modified_item->region = item->region;
            modified_item->quantity = item->quantity * 1.1;
            modified_item->cost = item->cost * 0.95;
            transformed_data[transformed_count++] = modified_item;
        }
    }
    return transformed_data;
}

void DataMutator_init(DataMutator *self, DataProcessor *processor) {
    self->processor = processor;
}

Item** DataMutator_mutate_data(DataMutator *self) {
    Item **mutated_data = (Item**)malloc(sizeof(Item*) * self->processor->size);
    int mutated_count = 0;
    for (int i = 0; i < self->processor->size; i++) {
        Item *item = self->processor->data[i];
        if (strcmp(item->category, "critical") == 0) {
            Item *altered_item = (Item*)malloc(sizeof(Item));
            altered_item->status = item->status;
            altered_item->category = item->category;
            altered_item->region = item->region;
            altered_item->quantity = item->quantity;
            altered_item->cost = item->cost;
            altered_item->priority = "high";
            altered_item->reorder = 1;
            mutated_data[mutated_count++] = altered_item;
        }
    }
    return mutated_data;
}

void DataAnalyzer_init(DataAnalyzer *self, DataMutator *mutator) {
    self->mutator = mutator;
}

RegionAnalysis* DataAnalyzer_analyze_data(DataAnalyzer *self) {
    RegionAnalysis *analysis = (RegionAnalysis*)malloc(sizeof(RegionAnalysis) * 10);
    int analysis_count = 0;
    for (int i = 0; i < self->mutator->processor->size; i++) {
        Item *item = self->mutator->processor->data[i];
        int found = 0;
        for (int j = 0; j < analysis_count; j++) {
            if (strcmp(item->region, analysis[j].region) == 0) {
                analysis[j].total_cost += item->cost;
                analysis[j].item_count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            analysis[analysis_count].region = item->region;
            analysis[analysis_count].total_cost = item->cost;
            analysis[analysis_count].item_count = 1;
            analysis_count++;
        }
    }
    return analysis;
}

int main() {
    Item *initial_data[] = {
        (Item*)malloc(sizeof(Item)), 
        (Item*)malloc(sizeof(Item)), 
        (Item*)malloc(sizeof(Item)), 
        (Item*)malloc(sizeof(Item))
    };
    initial_data[0]->status = "active";
    initial_data[0]->category = "critical";
    initial_data[0]->region = "north";
    initial_data[0]->quantity = 100;
    initial_data[0]->cost = 10;
    initial_data[1]->status = "inactive";
    initial_data[1]->category = "standard";
    initial_data[1]->region = "south";
    initial_data[1]->quantity = 200;
    initial_data[1]->cost = 20;
    initial_data[2]->status = "active";
    initial_data[2]->category = "critical";
    initial_data[2]->region = "east";
    initial_data[2]->quantity = 150;
    initial_data[2]->cost = 15;
    initial_data[3]->status = "active";
    initial_data[3]->category = "standard";
    initial_data[3]->region = "west";
    initial_data[3]->quantity = 300;
    initial_data[3]->cost = 30;

    DataProcessor processor;
    DataProcessor_init(&processor, initial_data, 4);
    Item **processed_data = DataProcessor_process_data(&processor);

    DataMutator mutator;
    DataMutator_init(&mutator, &processor);
    Item **mutated_data = DataMutator_mutate_data(&mutator);

    DataAnalyzer analyzer;
    DataAnalyzer_init(&analyzer, &mutator);
    RegionAnalysis *analysis = DataAnalyzer_analyze_data(&analyzer);

    for (int i = 0; i < 4; i++) {
        printf("%s: total_cost = %f, item_count = %d\n", analysis[i].region, analysis[i].total_cost, analysis[i].item_count);
    }

    return 0;
}