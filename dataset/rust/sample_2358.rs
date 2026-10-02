extern crate rand;
extern crate rand_distr;

use rand::Rng;
use rand_distr::{Normal, Distribution};

struct PValueSimulator {
    data: Vec<f64>,
}

impl PValueSimulator {
    fn new(size: usize) -> Self {
        let mut rng = rand::thread_rng();
        PValueSimulator {
            data: (0..size).map(|_| rng.gen()).collect(),
        }
    }

    fn calculate_p_value(&self) -> f64 {
        let mean = self.data.iter().sum::<f64>() / self.data.len() as f64;
        let variance = self.data.iter().map(|&x| (x - mean).powi(2)).sum::<f64>() / self.data.len() as f64;
        let std_dev = variance.sqrt();
        let normal = Normal::new(mean, std_dev).unwrap();
        rng.sample(normal)
    }
}

struct PermutationAnalyzer {
    simulator: PValueSimulator,
}

impl PermutationAnalyzer {
    fn new(simulator: PValueSimulator) -> Self {
        PermutationAnalyzer { simulator }
    }

    fn perform_permutations(&self, iterations: usize) -> Vec<f64> {
        (0..iterations).map(|_| self.simulator.calculate_p_value()).collect()
    }
}

struct DataAnalyzer {
    analyzer: PermutationAnalyzer,
}

impl DataAnalyzer {
    fn new(analyzer: PermutationAnalyzer) -> Self {
        DataAnalyzer { analyzer }
    }

    fn analyze_data(&self) {
        loop {
            let permutations = self.analyzer.perform_permutations(1000);
            let mean_p_value = permutations.iter().sum::<f64>() / permutations.len() as f64;
            println!("Mean P-Value: {}", mean_p_value);
        }
    }
}

fn main() {
    let size = 100;
    let simulator = PValueSimulator::new(size);
    let analyzer = PermutationAnalyzer::new(simulator);
    let data_analyzer = DataAnalyzer::new(analyzer);
    data_analyzer.analyze_data();
}