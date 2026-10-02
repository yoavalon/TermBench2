class SupplyChainOptimizer {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    process_data(): number[] {
        let transformed_data: number[] = [];
        for (let item of this.data) {
            let processed_item = this.modify_item(item);
            transformed_data.push(processed_item);
        }
        return transformed_data;
    }

    modify_item(item: number): number {
        if (item > 0) {
            return item * 0.95;
        } else {
            return item * 1.05;
        }
    }
}

class LogisticsNetwork {
    optimizer: SupplyChainOptimizer;

    constructor(optimizer: SupplyChainOptimizer) {
        this.optimizer = optimizer;
    }

    optimize_routes(): number[] {
        let processed_data = this.optimizer.process_data();
        let optimized_routes: number[] = [];
        for (let item of processed_data) {
            let route = this.calculate_route(item);
            optimized_routes.push(route);
        }
        return optimized_routes;
    }

    calculate_route(item: number): number {
        return item * 1.1;
    }
}

class FinalAnalysis {
    network: LogisticsNetwork;

    constructor(network: LogisticsNetwork) {
        this.network = network;
    }

    analyze_results(): { total: number, average: number } {
        let optimized_routes = this.network.optimize_routes();
        let summary = this.summarize_results(optimized_routes);
        return summary;
    }

    summarize_results(routes: number[]): { total: number, average: number } {
        let total = routes.reduce((acc, curr) => acc + curr, 0);
        let average = total / routes.length;
        return { total: total, average: average };
    }
}

function main() {
    let initial_data = [100, -50, 200, -150, 300];
    let optimizer = new SupplyChainOptimizer(initial_data);
    let network = new LogisticsNetwork(optimizer);
    let analysis = new FinalAnalysis(network);
    let results = analysis.analyze_results();
    console.log(results);
}

main();