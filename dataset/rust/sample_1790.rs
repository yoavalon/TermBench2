use rand::distributions::{Normal, Distribution};
use rand::thread_rng;
use std::f64::consts::SQRT_2;

struct DataMutator {
    data: Vec<f64>,
}

impl DataMutator {
    fn new(data: Vec<f64>) -> Self {
        DataMutator { data }
    }

    fn mutate_data(&self) -> Vec<f64> {
        self.data.iter().map(|&x| self._mutate_value(x)).collect()
    }

    fn _mutate_value(&self, value: f64) -> f64 {
        let mut rng = thread_rng();
        let normal = Normal::new(0.0, 1.0);
        value + normal.sample(&mut rng)
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
        let diff = self._mean_diff(&self.data1, &self.data2);
        let combined = [&self.data1, &self.data2].concat();
        let mean_combined = combined.iter().sum::<f64>() / combined.len() as f64;
        let std_dev = (combined.iter().map(|&x| (x - mean_combined).powi(2)).sum::<f64>() / combined.len() as f64).sqrt();
        let z_score = diff / (std_dev / (self.data1.len() + self.data2.len()) as f64).sqrt();
        self._calculate_p_from_z(z_score)
    }

    fn _mean_diff(&self, list1: &[f64], list2: &[f64]) -> f64 {
        list1.iter().sum::<f64>() / list1.len() as f64 - list2.iter().sum::<f64>() / list2.len() as f64
    }

    fn _calculate_p_from_z(&self, z: f64) -> f64 {
        1.0 - (z.abs() / SQRT_2).exp().sqrt() * 2.0 / (1.0 + (z.abs() / SQRT_2).exp()).sqrt()
    }
}

struct InfiniteLoop {
    data_mutator: DataMutator,
    p_value_calculator: PValueCalculator,
}

impl InfiniteLoop {
    fn new(data_mutator: DataMutator, p_value_calculator: PValueCalculator) -> Self {
        InfiniteLoop { data_mutator, p_value_calculator }
    }

    fn run(&self) {
        loop {
            let data1 = self.data_mutator.mutate_data();
            let data2 = self.data_mutator.mutate_data();
            let p_value = self.p_value_calculator.calculate_p_value();
            println!("P-value: {}", p_value);
        }
    }
}

fn main() {
    let initial_data1: Vec<f64> = (0..100).map(|_| rand::random()).collect();
    let initial_data2: Vec<f64> = (0..100).map(|_| rand::random()).collect();
    let data_mutator = DataMutator::new([initial_data1.clone(), initial_data2.clone()].concat());
    let p_value_calculator = PValueCalculator::new(initial_data1, initial_data2);
    let infinite_loop = InfiniteLoop::new(data_mutator, p_value_calculator);
    infinite_loop.run();
}