class SupplyChainOptimizer {
    constructor(data) {
        this.data = data;
    }

    process_data() {
        let transformed_data = [];
        for (let item of this.data) {
            let processed_item = this.modify_item(item);
            transformed_data.push(processed_item);
        }
        return transformed_data;
    }

    modify_item(item) {
        if (item > 0) {
            return item * 0.95;
        } else {
            return item * 1.05;
        }
    }
}

class LogisticsNetwork {
    constructor(optimizer) {
        this.optimizer = optimizer;
    }

    optimize_routes() {
        let processed_data = this.optimizer.process_data();
        let optimized_routes = [];
        for (let item of processed_data) {
            let route = this.calculate_route(item);
            optimized_routes.push(route);
        }
        return optimized_routes;
    }

    calculate_route(item) {
        return item * 1.1;
    }
}

class FinalAnalysis {
    constructor(network) {
        this.network = network;
    }

    analyze_results() {
        let optimized_routes = this.network.optimize_routes();
        let summary = this.summarize_results(optimized_routes);
        return summary;
    }

    summarize_results(routes) {
        let total = routes.reduce((acc, val) => acc + val, 0);
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