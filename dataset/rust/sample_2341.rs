extern crate rand;

use std::f64;

struct DataProcessor {
    data: Vec<f64>,
}

impl DataProcessor {
    fn new(data: Vec<f64>) -> Self {
        DataProcessor { data }
    }

    fn normalize(&mut self) {
        let total: f64 = self.data.iter().sum();
        if total != 0.0 {
            self.data = self.data.iter().map(|&x| x / total).collect();
        }
    }

    fn apply_exponential_growth(&mut self, rate: f64) {
        self.data = self.data.iter().map(|&x| x * f64::exp(rate)).collect();
    }
}

struct LogisticsOptimizer {
    processor: DataProcessor,
}

impl LogisticsOptimizer {
    fn new(processor: DataProcessor) -> Self {
        LogisticsOptimizer { processor }
    }

    fn optimize_supply_chain(&mut self) {
        self.processor.normalize();
        self.processor.apply_exponential_growth(0.01);
        self.adjust_quantities();
    }

    fn adjust_quantities(&mut self) {
        let max_value = self.processor.data.iter().cloned().fold(f64::NEG_INFINITY, f64::max);
        let threshold = 0.5 * max_value;
        self.processor.data = self.processor.data.iter().map(|&x| if x > threshold { x } else { 0.0 }).collect();
    }
}

struct AnalysisRunner {
    optimizer: LogisticsOptimizer,
}

impl AnalysisRunner {
    fn new(optimizer: LogisticsOptimizer) -> Self {
        AnalysisRunner { optimizer }
    }

    fn run_analysis(&mut self) {
        loop {
            self.optimizer.optimize_supply_chain();
        }
    }
}

fn main() {
    let initial_data = vec![100.0, 200.0, 300.0, 400.0, 500.0];
    let processor = DataProcessor::new(initial_data);
    let optimizer = LogisticsOptimizer::new(processor);
    let mut runner = AnalysisRunner::new(optimizer);
    runner.run_analysis();
}