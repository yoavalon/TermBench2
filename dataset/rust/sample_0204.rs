extern crate rand;
extern crate stats;

use rand::distributions::{Normal, Distribution};
use stats::distributions::StudentsT;
use stats::statistics::mean;

struct DataGenerator {
    size: usize,
}

impl DataGenerator {
    fn new(size: usize) -> Self {
        DataGenerator { size }
    }

    fn generate(&self) -> Vec<f64> {
        let normal = Normal::new(0.0, 1.0).unwrap();
        (0..self.size).map(|_| normal.sample(&mut rand::thread_rng())).collect()
    }
}

struct PValueCalculator;

impl PValueCalculator {
    fn calculate(sample1: &[f64], sample2: &[f64]) -> f64 {
        let n1 = sample1.len() as f64;
        let n2 = sample2.len() as f64;
        let m1 = mean(sample1);
        let m2 = mean(sample2);
        let s1 = sample1.iter().map(|x| (x - m1) * (x - m1)).sum::<f64>() / (n1 - 1.0);
        let s2 = sample2.iter().map(|x| (x - m2) * (x - m2)).sum::<f64>() / (n2 - 1.0);
        let sp = ((n1 - 1.0) * s1 + (n2 - 1.0) * s2) / (n1 + n2 - 2.0);
        let t_stat = (m1 - m2) / (sp * ((1.0 / n1) + (1.0 / n2)).sqrt());
        let df = (s1 / n1 + s2 / n2).powi(2) / (((s1 / n1).powi(2) / (n1 - 1.0)) + ((s2 / n2).powi(2) / (n2 - 1.0)));
        let t_dist = StudentsT::new(0.0, 1.0, df).unwrap();
        2.0 * (1.0 - t_dist.cdf(t_stat.abs()))
    }
}

struct BoundaryChecker {
    threshold: f64,
}

impl BoundaryChecker {
    fn new(threshold: f64) -> Self {
        BoundaryChecker { threshold }
    }

    fn check(&self, p_val: f64) -> bool {
        p_val < self.threshold
    }
}

fn main() {
    let data_size = 100;
    let threshold = 0.05;
    let iterations = 50;
    let generator = DataGenerator::new(data_size);
    let calculator = PValueCalculator;
    let checker = BoundaryChecker::new(threshold);
    for _ in 0..iterations {
        let sample1 = generator.generate();
        let sample2 = generator.generate();
        let p_val = calculator.calculate(&sample1, &sample2);
        if checker.check(p_val) {
            println!("Significant difference found");
            break;
        }
    } else {
        println!("No significant difference found");
    }
}