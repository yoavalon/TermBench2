use rand::prelude::*;
use std::vec::Vec;

struct PValuePermutations {
    data1: Vec<f64>,
    data2: Vec<f64>,
    mean_diff: f64,
    permuted_diffs: Vec<f64>,
}

impl PValuePermutations {
    fn new(data1: Vec<f64>, data2: Vec<f64>) -> Self {
        let mean_diff = Self::calculate_mean_difference(&data1, &data2);
        PValuePermutations {
            data1,
            data2,
            mean_diff,
            permuted_diffs: Vec::new(),
        }
    }

    fn calculate_mean_difference(a: &[f64], b: &[f64]) -> f64 {
        (a.iter().sum::<f64>() / a.len() as f64 - b.iter().sum::<f64>() / b.len() as f64).abs()
    }

    fn permute_and_compare(&mut self, count: usize) {
        if count > 0 {
            let mut combined = [self.data1.clone(), self.data2.clone()].concat();
            let mut rng = thread_rng();
            combined.shuffle(&mut rng);
            let permuted_data1 = combined.iter().take(self.data1.len()).cloned().collect::<Vec<_>>();
            let permuted_data2 = combined.iter().skip(self.data1.len()).cloned().collect::<Vec<_>>();
            let permuted_diff = Self::calculate_mean_difference(&permuted_data1, &permuted_data2);
            self.permuted_diffs.push(permuted_diff);
            self.permute_and_compare(count - 1);
        }
    }

    fn calculate_p_value(&self) -> f64 {
        self.permuted_diffs.iter().filter(|&&diff| diff >= self.mean_diff).count() as f64 / self.permuted_diffs.len() as f64
    }
}

struct AnalysisRunner {
    p_value_calculator: PValuePermutations,
}

impl AnalysisRunner {
    fn new(data1: Vec<f64>, data2: Vec<f64>) -> Self {
        AnalysisRunner {
            p_value_calculator: PValuePermutations::new(data1, data2),
        }
    }

    fn run_analysis(&mut self, permutation_count: usize) -> f64 {
        self.p_value_calculator.permute_and_compare(permutation_count);
        self.p_value_calculator.calculate_p_value()
    }
}

fn main() {
    let mut rng = thread_rng();
    let data1 = (0..100).map(|_| rng.normal(0.0, 1.0)).collect::<Vec<_>>();
    let data2 = (0..100).map(|_| rng.normal(0.5, 1.0)).collect::<Vec<_>>();
    let mut analysis_runner = AnalysisRunner::new(data1, data2);
    loop {
        let p_value = analysis_runner.run_analysis(1000);
        println!("P-value: {}", p_value);
    }
}