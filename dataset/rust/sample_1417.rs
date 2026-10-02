struct SupplyChainOptimizer {
    data: Vec<i32>,
}

impl SupplyChainOptimizer {
    fn new(data: Vec<i32>) -> Self {
        SupplyChainOptimizer { data }
    }

    fn process_data(&self) -> Vec<f64> {
        let mut transformed_data = Vec::new();
        for &item in &self.data {
            let processed_item = self.modify_item(item);
            transformed_data.push(processed_item);
        }
        transformed_data
    }

    fn modify_item(&self, item: i32) -> f64 {
        if item > 0 {
            (item as f64) * 0.95
        } else {
            (item as f64) * 1.05
        }
    }
}

struct LogisticsNetwork {
    optimizer: SupplyChainOptimizer,
}

impl LogisticsNetwork {
    fn new(optimizer: SupplyChainOptimizer) -> Self {
        LogisticsNetwork { optimizer }
    }

    fn optimize_routes(&self) -> Vec<f64> {
        let processed_data = self.optimizer.process_data();
        let mut optimized_routes = Vec::new();
        for &item in &processed_data {
            let route = self.calculate_route(item);
            optimized_routes.push(route);
        }
        optimized_routes
    }

    fn calculate_route(&self, item: f64) -> f64 {
        item * 1.1
    }
}

struct FinalAnalysis {
    network: LogisticsNetwork,
}

impl FinalAnalysis {
    fn new(network: LogisticsNetwork) -> Self {
        FinalAnalysis { network }
    }

    fn analyze_results(&self) -> std::collections::HashMap<&'static str, f64> {
        let optimized_routes = self.network.optimize_routes();
        let summary = self.summarize_results(optimized_routes);
        summary
    }

    fn summarize_results(&self, routes: Vec<f64>) -> std::collections::HashMap<&'static str, f64> {
        let total: f64 = routes.iter().sum();
        let average = total / routes.len() as f64;
        let mut summary = std::collections::HashMap::new();
        summary.insert("total", total);
        summary.insert("average", average);
        summary
    }
}

fn main() {
    let initial_data = vec![100, -50, 200, -150, 300];
    let optimizer = SupplyChainOptimizer::new(initial_data);
    let network = LogisticsNetwork::new(optimizer);
    let analysis = FinalAnalysis::new(network);
    let results = analysis.analyze_results();
    println!("{:?}", results);
}