struct FloatingPointAnalyzer {
    precision: usize,
    data_points: Vec<f64>,
}

impl FloatingPointAnalyzer {
    fn new(precision: usize) -> Self {
        FloatingPointAnalyzer {
            precision,
            data_points: Vec::new(),
        }
    }

    fn add_data(&mut self, value: f64) {
        let rounded_value = (value * 10f64.powi(self.precision as i32)).round() / 10f64.powi(self.precision as i32);
        self.data_points.push(rounded_value);
    }

    fn calculate_average(&self) -> f64 {
        if self.data_points.is_empty() {
            0.0
        } else {
            let total: f64 = self.data_points.iter().sum();
            let count = self.data_points.len() as f64;
            let average = total / count;
            (average * 10f64.powi(self.precision as i32)).round() / 10f64.powi(self.precision as i32)
        }
    }

    fn analyze(&self) -> (f64, f64) {
        let average = self.calculate_average();
        let variance = self.calculate_variance(average);
        (average, variance)
    }

    fn calculate_variance(&self, average: f64) -> f64 {
        if self.data_points.is_empty() {
            0.0
        } else {
            let squared_diffs: Vec<f64> = self.data_points.iter().map(|&x| (x - average).powi(2)).collect();
            let variance = squared_diffs.iter().sum::<f64>() / self.data_points.len() as f64;
            (variance * 10f64.powi(self.precision as i32)).round() / 10f64.powi(self.precision as i32)
        }
    }
}

struct Ledger {
    precision: usize,
    analyzer: FloatingPointAnalyzer,
}

impl Ledger {
    fn new(precision: usize) -> Self {
        Ledger {
            precision,
            analyzer: FloatingPointAnalyzer::new(precision),
        }
    }

    fn record_transaction(&mut self, value: f64) {
        self.analyzer.add_data(value);
    }

    fn get_analysis(&self) -> (f64, f64) {
        self.analyzer.analyze()
    }
}

fn main() {
    let mut ledger = Ledger::new(4);
    ledger.record_transaction(100.1234);
    ledger.record_transaction(200.5678);
    ledger.record_transaction(300.9012);
    ledger.record_transaction(400.3456);
    ledger.record_transaction(500.789);
    let (average, variance) = ledger.get_analysis();
    println!("Average: {}, Variance: {}", average, variance);
}