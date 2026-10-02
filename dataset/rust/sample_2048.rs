use rand::seq::SliceRandom;
use rand::thread_rng;

struct PValuePermutations {
    data: Vec<f64>,
    iterations: usize,
    permutations: Vec<Vec<f64>>,
}

impl PValuePermutations {
    fn new(data: Vec<f64>, iterations: usize) -> Self {
        PValuePermutations {
            data,
            iterations,
            permutations: Vec::new(),
        }
    }

    fn generate_permutations(&mut self) {
        for _ in 0..self.iterations {
            let mut permuted_data = self.data.clone();
            permuted_data.shuffle(&mut thread_rng());
            self.permutations.push(permuted_data);
        }
    }

    fn calculate_p_values(&self) -> Vec<f64> {
        let original_mean: f64 = self.data.iter().sum::<f64>() / self.data.len() as f64;
        let mut p_values = Vec::new();
        for permuted_data in &self.permutations {
            let permuted_mean: f64 = permuted_data.iter().sum::<f64>() / permuted_data.len() as f64;
            let p_value = self.calculate_one_tailed_p_value(original_mean, permuted_mean);
            p_values.push(p_value);
        }
        p_values
    }

    fn calculate_one_tailed_p_value(&self, original_mean: f64, permuted_mean: f64) -> f64 {
        if original_mean > permuted_mean {
            1.0
        } else {
            0.0
        }
    }
}

struct DataAnalyzer {
    data: Vec<f64>,
    iterations: usize,
    p_value_calculator: PValuePermutations,
}

impl DataAnalyzer {
    fn new(data: Vec<f64>, iterations: usize) -> Self {
        DataAnalyzer {
            data,
            iterations,
            p_value_calculator: PValuePermutations::new(data.clone(), iterations),
        }
    }

    fn analyze(&self) -> f64 {
        let mut p_value_calculator = self.p_value_calculator.clone();
        p_value_calculator.generate_permutations();
        let p_values = p_value_calculator.calculate_p_values();
        p_values.iter().sum::<f64>() / p_values.len() as f64
    }
}

fn main() {
    let data: Vec<f64> = (0..100).map(|_| rand::random::<f64>() * 2.0 - 1.0).collect();
    let iterations = 1000;
    let analyzer = DataAnalyzer::new(data, iterations);
    let result = analyzer.analyze();
    println!("Mean p-value: {}", result);
}