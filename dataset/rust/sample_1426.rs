use rand::distributions::StandardNormal;
use rand::seq::SliceRandom;
use rand::thread_rng;

struct DataGenerator {
    data: Vec<f64>,
}

impl DataGenerator {
    fn new(size: usize) -> Self {
        DataGenerator {
            data: (0..size).map(|_| rand::random::<StandardNormal>().sample(&mut thread_rng())).collect(),
        }
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

    fn calculate_p_value(&self) -> f64 {
        let mean1 = self.data1.iter().sum::<f64>() / self.data1.len() as f64;
        let mean2 = self.data2.iter().sum::<f64>() / self.data2.len() as f64;
        let diff = mean1 - mean2;
        let variance1 = self.data1.iter().map(|&x| (x - mean1).powi(2)).sum::<f64>() / self.data1.len() as f64;
        let variance2 = self.data2.iter().map(|&x| (x - mean2).powi(2)).sum::<f64>() / self.data2.len() as f64;
        diff / ((variance1 + variance2) as f64).sqrt()
    }
}

struct PermutationTester {
    data1: Vec<f64>,
    data2: Vec<f64>,
    iterations: usize,
}

impl PermutationTester {
    fn new(data1: Vec<f64>, data2: Vec<f64>, iterations: usize) -> Self {
        PermutationTester { data1, data2, iterations }
    }

    fn permute_and_test(&self) -> f64 {
        let original_p_value = PValueCalculator::new(self.data1.clone(), self.data2.clone()).calculate_p_value();
        let mut larger = 0;
        let mut combined_data = [self.data1.clone(), self.data2.clone()].concat();
        for _ in 0..self.iterations {
            combined_data.shuffle(&mut thread_rng());
            let new_data1 = combined_data[..self.data1.len()].to_vec();
            let new_data2 = combined_data[self.data1.len()..].to_vec();
            let new_p_value = PValueCalculator::new(new_data1, new_data2).calculate_p_value();
            if new_p_value.abs() >= original_p_value.abs() {
                larger += 1;
            }
        }
        larger as f64 / self.iterations as f64
    }
}

fn main() {
    let size = 100;
    let iterations = 1000;
    let generator1 = DataGenerator::new(size);
    let generator2 = DataGenerator::new(size);
    let tester = PermutationTester::new(generator1.data, generator2.data, iterations);
    let result = tester.permute_and_test();
    println!("{}", result);
}