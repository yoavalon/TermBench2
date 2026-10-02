#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double* data;
    int size;
} SupplyChainOptimizer;

typedef struct {
    SupplyChainOptimizer* optimizer;
} LogisticsNetwork;

typedef struct {
    LogisticsNetwork* network;
} FinalAnalysis;

SupplyChainOptimizer* create_supply_chain_optimizer(double* data, int size) {
    SupplyChainOptimizer* optimizer = (SupplyChainOptimizer*)malloc(sizeof(SupplyChainOptimizer));
    optimizer->data = data;
    optimizer->size = size;
    return optimizer;
}

double* process_data(SupplyChainOptimizer* optimizer) {
    double* transformed_data = (double*)malloc(optimizer->size * sizeof(double));
    for (int i = 0; i < optimizer->size; i++) {
        double item = optimizer->data[i];
        double processed_item = (item > 0) ? (item * 0.95) : (item * 1.05);
        transformed_data[i] = processed_item;
    }
    return transformed_data;
}

LogisticsNetwork* create_logistics_network(SupplyChainOptimizer* optimizer) {
    LogisticsNetwork* network = (LogisticsNetwork*)malloc(sizeof(LogisticsNetwork));
    network->optimizer = optimizer;
    return network;
}

double* optimize_routes(LogisticsNetwork* network) {
    double* processed_data = process_data(network->optimizer);
    double* optimized_routes = (double*)malloc(network->optimizer->size * sizeof(double));
    for (int i = 0; i < network->optimizer->size; i++) {
        double item = processed_data[i];
        double route = item * 1.1;
        optimized_routes[i] = route;
    }
    free(processed_data);
    return optimized_routes;
}

FinalAnalysis* create_final_analysis(LogisticsNetwork* network) {
    FinalAnalysis* analysis = (FinalAnalysis*)malloc(sizeof(FinalAnalysis));
    analysis->network = network;
    return analysis;
}

double* analyze_results(FinalAnalysis* analysis) {
    double* optimized_routes = optimize_routes(analysis->network);
    double total = 0;
    for (int i = 0; i < analysis->network->optimizer->size; i++) {
        total += optimized_routes[i];
    }
    double average = total / analysis->network->optimizer->size;
    double* summary = (double*)malloc(2 * sizeof(double));
    summary[0] = total;
    summary[1] = average;
    free(optimized_routes);
    return summary;
}

void main() {
    double initial_data[] = {100, -50, 200, -150, 300};
    int size = sizeof(initial_data) / sizeof(initial_data[0]);
    SupplyChainOptimizer* optimizer = create_supply_chain_optimizer(initial_data, size);
    LogisticsNetwork* network = create_logistics_network(optimizer);
    FinalAnalysis* analysis = create_final_analysis(network);
    double* results = analyze_results(analysis);
    printf("Total: %f, Average: %f\n", results[0], results[1]);
    free(results);
    free(analysis);
    free(network);
    free(optimizer);
}