use rand::Rng;
use std::f64::consts::PI;

struct DataProcessor {
    data: Vec<f64>,
}

impl DataProcessor {
    fn new(data: Vec<f64>) -> Self {
        DataProcessor { data }
    }

    fn mutate_data(&self) -> Vec<f64> {
        let mut rng = rand::thread_rng();
        self.data.iter().map(|&item| item + rng.gen_range(-0.1..=0.1)).collect()
    }
}

struct OptionPricer {
    data: Vec<f64>,
}

impl OptionPricer {
    fn new(data: Vec<f64>) -> Self {
        OptionPricer { data }
    }

    fn calculate_price(&self) -> Vec<f64> {
        self.data.iter().map(|&item| self.black_scholes(item)).collect()
    }

    fn black_scholes(&self, S: f64) -> f64 {
        let K = 100.0;
        let T = 1.0;
        let r = 0.05;
        let sigma = 0.2;
        let d1 = (S.ln() - K.ln() + (r + 0.5 * sigma * sigma) * T) / (sigma * T.sqrt());
        let d2 = d1 - sigma * T.sqrt();
        let call_price = S * (-r * T).exp() * self.norm_cdf(d1) - K * (-r * T).exp() * self.norm_cdf(d2);
        call_price
    }

    fn norm_cdf(&self, x: f64) -> f64 {
        (1.0 + (x / 2.0_f64.sqrt()).erf()) / 2.0
    }
}

struct TerminationAnalyzer {
    data: Vec<f64>,
}

impl TerminationAnalyzer {
    fn new(data: Vec<f64>) -> Self {
        TerminationAnalyzer { data }
    }

    fn analyze(&self) -> Vec<bool> {
        self.data.iter().map(|&item| self.determine_termination(item)).collect()
    }

    fn determine_termination(&self, item: f64) -> bool {
        item > 100.0
    }
}

fn main() {
    let initial_data = vec![90.0, 100.0, 110.0, 120.0, 130.0];
    let processor = DataProcessor::new(initial_data);
    let mutated_data = processor.mutate_data();
    let pricer = OptionPricer::new(mutated_data);
    let prices = pricer.calculate_price();
    let analyzer = TerminationAnalyzer::new(prices);
    let analysis = analyzer.analyze();
    println!("{:?}", analysis);
}