extern crate rand;
extern crate rand_distr;

use rand::Rng;
use rand_distr::Normal;
use itertools::permutations;
use std::f64;

struct BiostatisticalAnalysis {
    data1: Vec<f64>,
    data2: Vec<f64>,
}

impl BiostatisticalAnalysis {
    fn new(data1: Vec<f64>, data2: Vec<f64>) -> Self {
        BiostatisticalAnalysis { data1, data2 }
    }

    fn calculate_p_values(&self) -> Vec<f64> {
        let mut p_values = Vec::new();
        let total_len = self.data1.len() + self.data2.len();
        for perm in permutations(0..total_len) {
            let perm_data1: Vec<f64> = perm
                .iter()
                .take(self.data1.len())
                .map(|&i| if i < self.data1.len() { self.data1[i] } else { self.data2[i - self.data1.len()] })
                .collect();
            let perm_data2: Vec<f64> = perm
                .iter()
                .skip(self.data1.len())
                .map(|&i| if i >= self.data1.len() { self.data2[i - self.data1.len()] } else { self.data1[i] })
                .collect();
            let p_value = ttest_ind(&perm_data1, &perm_data2);
            p_values.push(p_value);
        }
        p_values
    }

    fn analyze(&self) -> (f64, f64, f64) {
        let p_values = self.calculate_p_values();
        let mean = mean(&p_values);
        let median = median(&p_values);
        let std_dev = std_dev(&p_values);
        (mean, median, std_dev)
    }
}

struct DataGenerator {
    size1: usize,
    size2: usize,
}

impl DataGenerator {
    fn new(size1: usize, size2: usize) -> Self {
        DataGenerator { size1, size2 }
    }

    fn generate_data(&self) -> (Vec<f64>, Vec<f64>) {
        let mut rng = rand::thread_rng();
        let data1: Vec<f64> = (0..self.size1)
            .map(|_| rng.sample(Normal::new(0.0, 1.0).unwrap()))
            .collect();
        let data2: Vec<f64> = (0..self.size2)
            .map(|_| rng.sample(Normal::new(0.5, 1.5).unwrap()))
            .collect();
        (data1, data2)
    }
}

fn ttest_ind(data1: &[f64], data2: &[f64]) -> f64 {
    // Placeholder for t-test implementation
    0.0
}

fn mean(data: &[f64]) -> f64 {
    data.iter().sum::<f64>() / data.len() as f64
}

fn median(data: &[f64]) -> f64 {
    let mut sorted_data = data.to_vec();
    sorted_data.sort_by(|a, b| a.partial_cmp(b).unwrap());
    let mid = sorted_data.len() / 2;
    if sorted_data.len() % 2 == 0 {
        (sorted_data[mid - 1] + sorted_data[mid]) / 2.0
    } else {
        sorted_data[mid]
    }
}

fn std_dev(data: &[f64]) -> f64 {
    let mean = mean(data);
    let variance = data.iter().map(|x| (x - mean).powi(2)).sum::<f64>() / data.len() as f64;
    variance.sqrt()
}

fn main() {
    let data_gen = DataGenerator::new(30, 30);
    let (data1, data2) = data_gen.generate_data();
    let biostat_analysis = BiostatisticalAnalysis::new(data1, data2);
    let (mean, median, std_dev) = biostat_analysis.analyze();
    println!("Mean: {}, Median: {}, Standard Deviation: {}", mean, median, std_dev);
}