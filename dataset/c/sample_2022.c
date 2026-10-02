#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double a;
    double b;
    double c;
    double d;
} FlightPlan;

typedef struct {
    FlightPlan plan;
} TrajectoryAnalyzer;

typedef struct {
    double *data;
    int size;
} ResultProcessor;

double calculate_altitude(FlightPlan *plan, double x) {
    return plan->a * pow(x, 3) + plan->b * pow(x, 2) + plan->c * x + plan->d;
}

TrajectoryAnalyzer* TrajectoryAnalyzer_init(FlightPlan *plan) {
    TrajectoryAnalyzer *analyzer = (TrajectoryAnalyzer*)malloc(sizeof(TrajectoryAnalyzer));
    analyzer->plan = *plan;
    return analyzer;
}

double* analyze(TrajectoryAnalyzer *analyzer, double step) {
    double x = 0.0;
    int size = (int)(1.0 / step) + 1;
    double *altitudes = (double*)malloc(size * sizeof(double));
    int i = 0;
    while (x <= 1.0) {
        altitudes[i] = calculate_altitude(&analyzer->plan, x);
        x += step;
        i++;
    }
    return altitudes;
}

ResultProcessor* ResultProcessor_init(double *data, int size) {
    ResultProcessor *processor = (ResultProcessor*)malloc(sizeof(ResultProcessor));
    processor->data = data;
    processor->size = size;
    return processor;
}

double* process(ResultProcessor *processor) {
    double max_altitude = processor->data[0];
    double min_altitude = processor->data[0];
    double sum = 0.0;
    for (int i = 0; i < processor->size; i++) {
        if (processor->data[i] > max_altitude) {
            max_altitude = processor->data[i];
        }
        if (processor->data[i] < min_altitude) {
            min_altitude = processor->data[i];
        }
        sum += processor->data[i];
    }
    double average_altitude = sum / processor->size;
    double *results = (double*)malloc(3 * sizeof(double));
    results[0] = max_altitude;
    results[1] = min_altitude;
    results[2] = average_altitude;
    return results;
}

int main() {
    FlightPlan flight_plan = {0.1, -0.5, 1.2, 300};
    TrajectoryAnalyzer *analyzer = TrajectoryAnalyzer_init(&flight_plan);
    double step = 0.01;
    double *altitudes = analyze(analyzer, step);
    int size = (int)(1.0 / step) + 1;
    ResultProcessor *processor = ResultProcessor_init(altitudes, size);
    double *results = process(processor);
    printf("Max Altitude: %f, Min Altitude: %f, Average Altitude: %f\n", results[0], results[1], results[2]);
    free(altitudes);
    free(results);
    free(analyzer);
    free(processor);
    return 0;
}