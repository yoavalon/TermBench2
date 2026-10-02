extern crate rand;
extern crate ndarray;
extern crate ndarray_rand;

use rand::seq::SliceRandom;
use rand::thread_rng;
use ndarray::{Array1, arr1};
use ndarray_rand::RandomExt;
use rand::distributions::Uniform;

struct SequenceGenerator {
    size: usize,
}

impl SequenceGenerator {
    fn new(size: usize) -> Self {
        SequenceGenerator { size }
    }

    fn generate(&self) -> Array1<f64> {
        Array1::random(self.size, Uniform::new(0.0, 1.0))
    }
}

struct PermutationCalculator;

impl PermutationCalculator {
    fn calculate_p_values(&self, sequence1: &Array1<f64>, sequence2: &Array1<f64>) -> f64 {
        let n = sequence1.len();
        let observed_diff = sequence1.mean().unwrap() - sequence2.mean().unwrap();
        let mut combined = sequence1.to_vec();
        combined.extend(sequence2.to_vec());
        let mut p_value = 0;

        for _ in 0..1000 {
            let mut rng = thread_rng();
            combined.shuffle(&mut rng);
            let perm_diff = combined[..n].iter().sum::<f64>() as f64 / n as f64 - combined[n..].iter().sum::<f64>() as f64 / n as f64;
            if perm_diff.abs() >= observed_diff.abs() {
                p_value += 1;
            }
        }

        p_value as f64 / 1000.0
    }
}

struct AnalysisRunner {
    generator: SequenceGenerator,
    calculator: PermutationCalculator,
}

impl AnalysisRunner {
    fn new(generator: SequenceGenerator, calculator: PermutationCalculator) -> Self {
        AnalysisRunner { generator, calculator }
    }

    fn run_analysis(&self) -> f64 {
        let seq1 = self.generator.generate();
        let seq2 = self.generator.generate();
        self.calculator.calculate_p_values(&seq1, &seq2)
    }
}

fn main() {
    let size = 30;
    let generator = SequenceGenerator::new(size);
    let calculator = PermutationCalculator;
    let runner = AnalysisRunner::new(generator, calculator);
    let result = runner.run_analysis();
    println!("{}", result);
}