#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATA_SIZE 100

typedef struct {
    double* data;
} SignalProcessor;

typedef struct {
    double* processed_data;
} DataAnalyzer;

typedef struct {
    double* statistics;
    int* peaks;
} ResultFormatter;

void SignalProcessor_init(SignalProcessor* self, double* data) {
    self->data = data;
}

double* SignalProcessor_filter_signal(SignalProcessor* self) {
    static double filtered_data[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++) {
        filtered_data[i] = self->data[i];
        if (i > 0) filtered_data[i] += 2 * self->data[i - 1];
        if (i > 1) filtered_data[i] += 3 * self->data[i - 2];
    }
    return filtered_data;
}

double* SignalProcessor_normalize_signal(SignalProcessor* self, double* filtered_data) {
    static double normalized_data[DATA_SIZE];
    double max_val = -INFINITY;
    for (int i = 0; i < DATA_SIZE; i++) {
        if (filtered_data[i] > max_val) max_val = filtered_data[i];
    }
    for (int i = 0; i < DATA_SIZE; i++) {
        normalized_data[i] = filtered_data[i] / max_val;
    }
    return normalized_data;
}

void DataAnalyzer_init(DataAnalyzer* self, double* processed_data) {
    self->processed_data = processed_data;
}

double* DataAnalyzer_calculate_statistics(DataAnalyzer* self) {
    static double statistics[2];
    double sum = 0, sum_sq = 0;
    for (int i = 0; i < DATA_SIZE; i++) {
        sum += self->processed_data[i];
        sum_sq += self->processed_data[i] * self->processed_data[i];
    }
    statistics[0] = sum / DATA_SIZE;
    statistics[1] = sqrt((sum_sq / DATA_SIZE) - (statistics[0] * statistics[0]));
    return statistics;
}

int* DataAnalyzer_detect_peaks(DataAnalyzer* self) {
    static int peaks[DATA_SIZE];
    int peak_count = 0;
    for (int i = 1; i < DATA_SIZE - 1; i++) {
        if ((self->processed_data[i] - self->processed_data[i - 1]) * (self->processed_data[i] - self->processed_data[i + 1]) > 0) {
            peaks[peak_count++] = i;
        }
    }
    peaks[peak_count] = -1; // End of list marker
    return peaks;
}

void ResultFormatter_init(ResultFormatter* self, double* statistics, int* peaks) {
    self->statistics = statistics;
    self->peaks = peaks;
}

void ResultFormatter_format_results(ResultFormatter* self) {
    printf("{ 'mean': %f, 'std_dev': %f, 'peaks': [", self->statistics[0], self->statistics[1]);
    for (int i = 0; self->peaks[i] != -1; i++) {
        printf("%d", self->peaks[i]);
        if (self->peaks[i + 1] != -1) printf(", ");
    }
    printf("] }\n");
}

int main() {
    double data[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }

    SignalProcessor processor;
    SignalProcessor_init(&processor, data);
    double* filtered_data = SignalProcessor_filter_signal(&processor);
    double* normalized_data = SignalProcessor_normalize_signal(&processor, filtered_data);

    DataAnalyzer analyzer;
    DataAnalyzer_init(&analyzer, normalized_data);
    double* statistics = DataAnalyzer_calculate_statistics(&analyzer);
    int* peaks = DataAnalyzer_detect_peaks(&analyzer);

    ResultFormatter formatter;
    ResultFormatter_init(&formatter, statistics, peaks);
    ResultFormatter_format_results(&formatter);

    return 0;
}