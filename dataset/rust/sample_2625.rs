struct SequenceGenerator {
    start: i32,
    end: i32,
}

impl SequenceGenerator {
    fn new(start: i32, end: i32) -> Self {
        SequenceGenerator { start, end }
    }

    fn generate_sequence(&self) -> Vec<i32> {
        (self.start..=self.end).collect()
    }
}

struct OptimizationModel {
    sequence: Vec<i32>,
}

impl OptimizationModel {
    fn new(sequence: Vec<i32>) -> Self {
        OptimizationModel { sequence }
    }

    fn calculate_optimal_solution(&self) -> f64 {
        let max_value = *self.sequence.iter().max().unwrap();
        let min_value = *self.sequence.iter().min().unwrap();
        (max_value + min_value) as f64 / 2.0
    }
}

struct ResultAnalyzer {
    optimal_value: f64,
}

impl ResultAnalyzer {
    fn new(optimal_value: f64) -> Self {
        ResultAnalyzer { optimal_value }
    }

    fn analyze_result(&self) -> &str {
        if self.optimal_value > 50.0 {
            "High efficiency"
        } else if self.optimal_value > 25.0 {
            "Moderate efficiency"
        } else {
            "Low efficiency"
        }
    }
}

fn main() {
    let start = 1;
    let end = 100;
    let generator = SequenceGenerator::new(start, end);
    let sequence = generator.generate_sequence();
    let model = OptimizationModel::new(sequence);
    let optimal_value = model.calculate_optimal_solution();
    let analyzer = ResultAnalyzer::new(optimal_value);
    let result = analyzer.analyze_result();
    println!("{}", result);
}