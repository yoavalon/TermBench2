#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int quantity;
    float price;
} DataItem;

typedef struct {
    DataItem* data;
    int size;
} DataProcessor;

typedef struct {
    DataItem* processed_data;
    int size;
} AnalysisEngine;

typedef struct {
    float analysis_result;
} ReportingTool;

DataProcessor* DataProcessor_init(DataItem* data, int size) {
    DataProcessor* self = (DataProcessor*)malloc(sizeof(DataProcessor));
    self->data = data;
    self->size = size;
    return self;
}

DataItem* transform(DataProcessor* self, int* transformed_size) {
    DataItem* transformed_data = (DataItem*)malloc(self->size * sizeof(DataItem));
    *transformed_size = 0;
    for (int i = 0; i < self->size; i++) {
        if (self->data[i].quantity > 0) {
            transformed_data[*transformed_size].name = strdup(self->data[i].name);
            transformed_data[*transformed_size].quantity = self->data[i].quantity;
            transformed_data[*transformed_size].price = self->data[i].quantity * self->data[i].price;
            (*transformed_size)++;
        }
    }
    return transformed_data;
}

AnalysisEngine* AnalysisEngine_init(DataItem* processed_data, int size) {
    AnalysisEngine* self = (AnalysisEngine*)malloc(sizeof(AnalysisEngine));
    self->processed_data = processed_data;
    self->size = size;
    return self;
}

float analyze(AnalysisEngine* self) {
    float total_value = 0;
    for (int i = 0; i < self->size; i++) {
        total_value += self->processed_data[i].price;
    }
    return total_value;
}

ReportingTool* ReportingTool_init(float analysis_result) {
    ReportingTool* self = (ReportingTool*)malloc(sizeof(ReportingTool));
    self->analysis_result = analysis_result;
    return self;
}

char* report(ReportingTool* self) {
    char* result = (char*)malloc(100 * sizeof(char));
    sprintf(result, "Total Supply Chain Value: %.2f", self->analysis_result);
    return result;
}

void main() {
    DataItem data[] = {
        {"Widget A", 100, 5.5},
        {"Widget B", 200, 3.75},
        {"Widget C", 0, 8.0}
    };
    int data_size = sizeof(data) / sizeof(data[0]);

    DataProcessor* processor = DataProcessor_init(data, data_size);
    int transformed_size;
    DataItem* transformed_data = transform(processor, &transformed_size);
    AnalysisEngine* analyzer = AnalysisEngine_init(transformed_data, transformed_size);
    float analysis_result = analyze(analyzer);
    ReportingTool* reporter = ReportingTool_init(analysis_result);
    char* result = report(reporter);

    printf("%s\n", result);

    free(result);
    free(transformed_data);
    free(processor);
    free(analyzer);
    free(reporter);
}

int main() {
    main();
    return 0;
}