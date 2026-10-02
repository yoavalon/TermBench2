#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* sequence;
    int current_frame;
    int capacity;
} FrameProcessor;

FrameProcessor* FrameProcessor_init() {
    FrameProcessor* processor = (FrameProcessor*)malloc(sizeof(FrameProcessor));
    processor->sequence = (int*)malloc(0);
    processor->current_frame = 0;
    processor->capacity = 0;
    return processor;
}

void FrameProcessor_add_frame(FrameProcessor* processor, int data) {
    processor->capacity++;
    processor->sequence = (int*)realloc(processor->sequence, processor->capacity * sizeof(int));
    processor->sequence[processor->current_frame] = data;
    processor->current_frame++;
}

int FrameProcessor_get_current_frame(FrameProcessor* processor) {
    return processor->sequence[processor->current_frame - 1];
}

void FrameProcessor_reset_sequence(FrameProcessor* processor) {
    free(processor->sequence);
    processor->sequence = (int*)malloc(0);
    processor->current_frame = 0;
    processor->capacity = 0;
}

typedef struct {
    FrameProcessor* processor;
} DataAnalyzer;

DataAnalyzer* DataAnalyzer_init() {
    DataAnalyzer* analyzer = (DataAnalyzer*)malloc(sizeof(DataAnalyzer));
    analyzer->processor = FrameProcessor_init();
    return analyzer;
}

void DataAnalyzer_analyze(DataAnalyzer* analyzer, int* data_stream, int length) {
    for (int i = 0; i < length; i++) {
        FrameProcessor_add_frame(analyzer->processor, data_stream[i]);
        int current_frame = FrameProcessor_get_current_frame(analyzer->processor);
        printf("Processing frame %d: %d\n", analyzer->processor->current_frame, current_frame);
    }
}

void DataAnalyzer_reset(DataAnalyzer* analyzer) {
    FrameProcessor_reset_sequence(analyzer->processor);
}

typedef struct {
    DataAnalyzer* analyzer;
} Controller;

Controller* Controller_init() {
    Controller* controller = (Controller*)malloc(sizeof(Controller));
    controller->analyzer = DataAnalyzer_init();
    return controller;
}

void Controller_run(Controller* controller, int* data_stream, int length) {
    while (1) {
        DataAnalyzer_analyze(controller->analyzer, data_stream, length);
        DataAnalyzer_reset(controller->analyzer);
    }
}

int main() {
    int data_stream[] = {1, 2, 3, 4, 5};
    int length = sizeof(data_stream) / sizeof(data_stream[0]);
    Controller* controller = Controller_init();
    Controller_run(controller, data_stream, length);
    return 0;
}