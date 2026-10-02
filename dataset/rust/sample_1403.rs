extern crate rand;
use rand::seq::SliceRandom;
use rand::thread_rng;

struct DataManipulator {
    data: Vec<f64>,
}

impl DataManipulator {
    fn new(data: Vec<f64>) -> Self {
        DataManipulator { data }
    }

    fn shuffle_data(&mut self) {
        self.data.shuffle(&mut thread_rng());
    }
}

struct PValueCalculator {
    data1: Vec<f64>,
    data2: Vec<f64>,
}

impl PValueCalculator {
    fn new(data1: Vec<f64>, data2: Vec<f64>) -> Self {
        PValueCalculator { data1, data2 }
    }

    fn calculate_pvalue(&self) -> f64 {
        self.data1.iter().sum::<f64>() / self.data1.len() as f64 - self.data2.iter().sum::<f64>() / self.data2.len() as f64
    }
}

struct PermutationAnalyzer {
    data1: Vec<f64>,
    data2: Vec<f64>,
    iterations: usize,
}

impl PermutationAnalyzer {
    fn new(data1: Vec<f64>, data2: Vec<f64>, iterations: usize) -> Self {
        PermutationAnalyzer { data1, data2, iterations }
    }

    fn run_permutations(&self) -> Vec<f64> {
        let mut p_values = Vec::new();
        let mut combined_data = [self.data1.clone(), self.data2.clone()].concat();
        for _ in 0..self.iterations {
            combined_data.shuffle(&mut thread_rng());
            let split_index = self.data1.len();
            let perm_data1 = combined_data[..split_index].to_vec();
            let perm_data2 = combined_data[split_index..].to_vec();
            let calculator = PValueCalculator::new(perm_data1, perm_data2);
            p_values.push(calculator.calculate_pvalue());
        }
        p_values
    }
}

fn main() {
    let data1: Vec<f64> = (0..100).map(|_| rand::random::<f64>() * 1.0 - 0.5).collect();
    let data2: Vec<f64> = (0..100).map(|_| rand::random::<f64>() * 1.0 + 0.5).collect();
    let iterations = 1000;
    let mut manipulator = DataManipulator::new(data1.clone());
    manipulator.shuffle_data();
    let shuffled_data1 = manipulator.data;
    let analyzer = PermutationAnalyzer::new(shuffled_data1, data2, iterations);
    let p_values = analyzer.run_permutations();
    let original_pvalue = PValueCalculator::new(data1, data2).calculate_pvalue();
    println!("Original p-value: {}", original_pvalue);
    println!("Permutation p-values: {:?}", p_values);
}