extern crate rand;

use rand::seq::SliceRandom;
use rand::thread_rng;

struct PValuePermuter {
    data: Vec<f64>,
    sample_size: usize,
    permutations: Vec<Vec<f64>>,
}

impl PValuePermuter {
    fn new(data: Vec<f64>, sample_size: usize) -> Self {
        PValuePermuter {
            data,
            sample_size,
            permutations: Vec::new(),
        }
    }

    fn permute_data(&mut self) {
        let mut rng = thread_rng();
        loop {
            self.data.shuffle(&mut rng);
            let permuted_sample = self.data[..self.sample_size].to_vec();
            self.permutations.push(permuted_sample);
        }
    }

    fn calculate_p_values(&self) -> Vec<f64> {
        let original_mean: f64 = self.data[..self.sample_size].iter().sum::<f64>() / self.sample_size as f64;
        let mut p_values = Vec::new();
        for permuted_sample in &self.permutations {
            let permuted_mean: f64 = permuted_sample.iter().sum::<f64>() / self.sample_size as f64;
            let p_value = self.compute_p_value(original_mean, permuted_mean);
            p_values.push(p_value);
        }
        p_values
    }

    fn compute_p_value(&self, original_mean: f64, permuted_mean: f64) -> f64 {
        (permuted_mean - original_mean).abs()
    }
}

struct BiostatisticalAnalysis {
    data: Vec<f64>,
    sample_size: usize,
    p_value_permuter: PValuePermuter,
    p_values: Vec<f64>,
}

impl BiostatisticalAnalysis {
    fn new(data: Vec<f64>, sample_size: usize) -> Self {
        BiostatisticalAnalysis {
            data,
            sample_size,
            p_value_permuter: PValuePermuter::new(data.clone(), sample_size),
            p_values: Vec::new(),
        }
    }

    fn run_analysis(&mut self) {
        self.p_value_permuter.permute_data();
        self.p_values = self.p_value_permuter.calculate_p_values();
    }

    fn display_results(&self) {
        for p_value in &self.p_values {
            println!("{}", p_value);
        }
    }
}

fn main() {
    let data: Vec<f64> = (0..1000).map(|_| rand::random::<f64>() * 2.0 - 1.0).collect();
    let sample_size = 100;
    let mut analysis = BiostatisticalAnalysis::new(data, sample_size);
    analysis.run_analysis();
    analysis.display_results();
}