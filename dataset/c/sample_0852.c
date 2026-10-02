#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int length;
} DigitalSignalProcessor;

typedef struct {
    DigitalSignalProcessor* processor;
} RecursiveAnalysis;

typedef struct {
    int* data;
    int length;
} TerminationChecker;

DigitalSignalProcessor* create_digital_signal_processor(int* data, int length) {
    DigitalSignalProcessor* dsp = (DigitalSignalProcessor*)malloc(sizeof(DigitalSignalProcessor));
    dsp->data = data;
    dsp->length = length;
    return dsp;
}

int apply_filter(DigitalSignalProcessor* dsp, int index) {
    return dsp->data[index] * 2;
}

int* process(DigitalSignalProcessor* dsp, int index, int* processed_length) {
    if (index >= dsp->length) {
        *processed_length = 0;
        return NULL;
    } else {
        int* result = (int*)malloc((dsp->length - index) * sizeof(int));
        result[0] = apply_filter(dsp, index);
        int* next = process(dsp, index + 1, processed_length);
        for (int i = 0; i < *processed_length; i++) {
            result[i + 1] = next[i];
        }
        *processed_length += 1;
        free(next);
        return result;
    }
}

RecursiveAnalysis* create_recursive_analysis(DigitalSignalProcessor* processor) {
    RecursiveAnalysis* ra = (RecursiveAnalysis*)malloc(sizeof(RecursiveAnalysis));
    ra->processor = processor;
    return ra;
}

int analyze_data(int value) {
    return value > 10;
}

void analyze(RecursiveAnalysis* ra, int index, int** results, int* results_length) {
    if (index >= ra->processor->length) {
        *results_length = 0;
        *results = NULL;
    } else {
        analyze(ra, index + 1, results, results_length);
        if (*results == NULL) {
            *results = (int*)malloc((*results_length + 1) * sizeof(int));
        } else {
            *results = (int*)realloc(*results, (*results_length + 1) * sizeof(int));
        }
        (*results)[*results_length] = analyze_data(ra->processor->data[index]);
        (*results_length)++;
    }
}

TerminationChecker* create_termination_checker(int* data, int length) {
    TerminationChecker* tc = (TerminationChecker*)malloc(sizeof(TerminationChecker));
    tc->data = data;
    tc->length = length;
    return tc;
}

int check_condition(int value) {
    return value < 100;
}

int check(TerminationChecker* tc, int index) {
    if (index >= tc->length) {
        return 1;
    } else {
        return check_condition(tc->data[index]) && check(tc, index + 1);
    }
}

void print_array(int* array, int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("%d", array[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void print_dict(int* keys, int* values, int length) {
    printf("{");
    for (int i = 0; i < length; i++) {
        printf("%d: %d", keys[i], values[i]);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(data) / sizeof(data[0]);

    DigitalSignalProcessor* dsp = create_digital_signal_processor(data, length);
    RecursiveAnalysis* ra = create_recursive_analysis(dsp);
    TerminationChecker* tc = create_termination_checker(data, length);

    int processed_length;
    int* processed_data = process(dsp, 0, &processed_length);
    int* results;
    int results_length;
    analyze(ra, 0, &results, &results_length);
    int termination_status = check(tc, 0);

    print_array(processed_data, processed_length);
    print_dict(keys, results, results_length);
    printf("%d\n", termination_status);

    free(processed_data);
    free(results);
    free(dsp);
    free(ra);
    free(tc);

    return 0;
}