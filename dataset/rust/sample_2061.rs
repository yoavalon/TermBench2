struct Simulation {
    a: f64,
    b: f64,
    c: f64,
}

impl Simulation {
    fn new(a: f64, b: f64, c: f64) -> Self {
        Simulation { a, b, c }
    }

    fn calculate(&self, x: f64) -> f64 {
        self.a * x.powi(2) + self.b * x + self.c
    }
}

struct PrecisionAnalyzer {
    simulation: Simulation,
}

impl PrecisionAnalyzer {
    fn new(simulation: Simulation) -> Self {
        PrecisionAnalyzer { simulation }
    }

    fn analyze(&self, x_values: Vec<f64>) -> Vec<f64> {
        let mut results = Vec::new();
        for x in x_values {
            let result = self.simulation.calculate(x);
            results.push(result);
        }
        results
    }
}

struct DataProcessor {
    analyzer: PrecisionAnalyzer,
}

impl DataProcessor {
    fn new(analyzer: PrecisionAnalyzer) -> Self {
        DataProcessor { analyzer }
    }

    fn process(&self, x_values: Vec<f64>) -> Vec<f64> {
        let raw_data = self.analyzer.analyze(x_values);
        let processed_data = self.format_data(raw_data);
        processed_data
    }

    fn format_data(&self, data: Vec<f64>) -> Vec<f64> {
        data.iter().map(|&value| (value * 100000.0).round() / 100000.0).collect()
    }
}

fn main() {
    let sim = Simulation::new(2.0, 3.0, 1.0);
    let analyzer = PrecisionAnalyzer::new(sim);
    let processor = DataProcessor::new(analyzer);
    let x_values = vec![0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0];
    let processed_results = processor.process(x_values);
    for (i, value) in processed_results.iter().enumerate() {
        println!("X: {}, Result: {}", x_values[i], value);
    }
}