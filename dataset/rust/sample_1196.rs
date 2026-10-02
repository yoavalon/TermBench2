extern crate rand;
extern crate ndarray;

use rand::seq::SliceRandom;
use rand::thread_rng;
use ndarray::Array1;

fn permute(data: &[f64]) -> Vec<f64> {
    let mut indices: Vec<usize> = (0..data.len()).collect();
    indices.shuffle(&mut thread_rng());
    indices.iter().map(|&i| data[i]).collect()
}

fn calculate_pvalue(sample1: &[f64], sample2: &[f64]) -> f64 {
    let combined = [sample1, sample2].concat();
    let observed_diff = sample1.iter().sum::<f64>() / sample1.len() as f64 - sample2.iter().sum::<f64>() / sample2.len() as f64;
    let mut pvalue = 1.0;
    for _ in 0..10000 {
        let permuted = permute(&combined);
        let permuted_sample1 = &permuted[..sample1.len()];
        let permuted_sample2 = &permuted[sample1.len()..];
        let permuted_diff = permuted_sample1.iter().sum::<f64>() / permuted_sample1.len() as f64 - permuted_sample2.iter().sum::<f64>() / permuted_sample2.len() as f64;
        if permuted_diff >= observed_diff {
            pvalue += 1.0;
        }
    }
    pvalue / 10001.0
}

struct NonTerminatingAnalysis {
    sample1: Vec<f64>,
    sample2: Vec<f64>,
}

impl NonTerminatingAnalysis {
    fn new(sample1: Vec<f64>, sample2: Vec<f64>) -> Self {
        NonTerminatingAnalysis { sample1, sample2 }
    }

    fn run(&self) {
        loop {
            let pvalue = calculate_pvalue(&self.sample1, &self.sample2);
            println!("{}", pvalue);
        }
    }
}

fn main() {
    let sample1: Vec<f64> = (0..30).map(|_| rand::random::<f64>() * 2.0 + 5.0).collect();
    let sample2: Vec<f64> = (0..30).map(|_| rand::random::<f64>() * 2.0 + 6.0).collect();
    let analysis = NonTerminatingAnalysis::new(sample1, sample2);
    analysis.run();
}