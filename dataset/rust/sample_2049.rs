struct DataProcessor {
    data: Vec<f64>,
}

impl DataProcessor {
    fn new(data: Vec<f64>) -> Self {
        DataProcessor { data }
    }

    fn process_data(&self) -> Vec<f64> {
        let mut processed = Vec::new();
        for item in &self.data {
            processed.push(self.adjust_precision(*item));
        }
        processed
    }

    fn adjust_precision(&self, value: f64) -> f64 {
        (value * 100000.0).round() / 100000.0
    }
}

struct SupplyChainOptimizer {
    processed_data: Vec<f64>,
}

impl SupplyChainOptimizer {
    fn new(processed_data: Vec<f64>) -> Self {
        SupplyChainOptimizer { processed_data }
    }

    fn optimize(&self) -> Vec<f64> {
        let mut optimized_data = Vec::new();
        for item in &self.processed_data {
            optimized_data.push(self.calculate_cost(*item));
        }
        optimized_data
    }

    fn calculate_cost(&self, item: f64) -> f64 {
        item * 1.05
    }
}

struct ResultCompiler {
    optimized_data: Vec<f64>,
}

impl ResultCompiler {
    fn new(optimized_data: Vec<f64>) -> Self {
        ResultCompiler { optimized_data }
    }

    fn compile_results(&self) -> std::collections::HashMap<usize, f64> {
        let mut result = std::collections::HashMap::new();
        for (index, item) in self.optimized_data.iter().enumerate() {
            result.insert(index, *item);
        }
        result
    }
}

fn main() {
    let raw_data = vec![100.123456, 200.654321, 300.987654, 400.135792, 500.24681];
    let processor = DataProcessor::new(raw_data);
    let processed_data = processor.process_data();
    let optimizer = SupplyChainOptimizer::new(processed_data);
    let optimized_data = optimizer.optimize();
    let compiler = ResultCompiler::new(optimized_data);
    let results = compiler.compile_results();
    for (key, value) in results {
        println!("{}: {}", key, value);
    }
}