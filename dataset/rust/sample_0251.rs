struct DataProcessor {
    data: Vec<i32>,
}

impl DataProcessor {
    fn new(data: Vec<i32>) -> Self {
        DataProcessor { data }
    }

    fn preprocess(&self) -> Vec<i32> {
        let mut processed_data = Vec::new();
        for &item in &self.data {
            if item > 0 {
                processed_data.push(item);
            }
        }
        processed_data
    }

    fn calculate(&self, processed_data: Vec<i32>) -> i32 {
        let mut total = 0;
        for &item in &processed_data {
            total += item * 2;
        }
        total
    }
}

struct Optimizer {
    result: i32,
}

impl Optimizer {
    fn new(result: i32) -> Self {
        Optimizer { result }
    }

    fn optimize(&self) -> i32 {
        self.result * 95 / 100
    }
}

struct TerminationAnalyzer {
    optimized_result: i32,
}

impl TerminationAnalyzer {
    fn new(optimized_result: i32) -> Self {
        TerminationAnalyzer { optimized_result }
    }

    fn analyze(&self) -> bool {
        self.optimized_result < 100
    }
}

fn main() {
    let initial_data = vec![10, -5, 20, 0, 15];
    let processor = DataProcessor::new(initial_data);
    let processed_data = processor.preprocess();
    let calculator = Optimizer::new(processor.calculate(processed_data));
    let optimized_result = calculator.optimize();
    let analyzer = TerminationAnalyzer::new(optimized_result);
    let analysis_result = analyzer.analyze();
    println!("{}", analysis_result);
}