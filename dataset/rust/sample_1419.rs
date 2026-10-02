use rand::Rng;

struct SupplyChainOptimizer {
    data: Vec<f64>,
    optimized_data: Vec<f64>,
}

impl SupplyChainOptimizer {
    fn new(data: Vec<f64>) -> Self {
        SupplyChainOptimizer {
            data,
            optimized_data: Vec::new(),
        }
    }

    fn process_data(&mut self) {
        for &item in &self.data {
            self.optimized_data.push(self.mutate_item(item));
        }
    }

    fn mutate_item(&self, item: f64) -> f64 {
        let mutation_factor: f64 = rand::thread_rng().gen_range(0.8..1.2);
        item * mutation_factor
    }
}

struct DataProcessor {
    data: Vec<f64>,
}

impl DataProcessor {
    fn new(data: Vec<f64>) -> Self {
        DataProcessor { data }
    }

    fn normalize_data(&self) -> Vec<f64> {
        let min_val = self.data.iter().cloned().fold(f64::INFINITY, f64::min);
        let max_val = self.data.iter().cloned().fold(f64::NEG_INFINITY, f64::max);
        self.data.iter().map(|&x| (x - min_val) / (max_val - min_val)).collect()
    }
}

struct DataAnalyzer {
    data: Vec<f64>,
}

impl DataAnalyzer {
    fn new(data: Vec<f64>) -> Self {
        DataAnalyzer { data }
    }

    fn calculate_statistics(&self) -> (f64, f64) {
        let mean = self.data.iter().sum::<f64>() / self.data.len() as f64;
        let variance = self.data.iter().map(|&x| (x - mean) * (x - mean)).sum::<f64>() / self.data.len() as f64;
        (mean, variance)
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    let raw_data: Vec<f64> = (0..100).map(|_| rng.gen_range(10.0..=100.0)).collect();
    let processor = DataProcessor::new(raw_data);
    let normalized_data = processor.normalize_data();
    let mut optimizer = SupplyChainOptimizer::new(normalized_data);
    optimizer.process_data();
    let optimized_data = optimizer.optimized_data;
    let analyzer = DataAnalyzer::new(optimized_data);
    let (mean, variance) = analyzer.calculate_statistics();
    println!("Mean: {}, Variance: {}", mean, variance);
}