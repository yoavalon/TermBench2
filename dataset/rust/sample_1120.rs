use rand::Rng;
use std::f64;

struct DataGenerator {
    data: Vec<f64>,
}

impl DataGenerator {
    fn new(size: usize) -> Self {
        let mut rng = rand::thread_rng();
        let data = (0..size).map(|_| rng.gen::<f64>()).collect();
        DataGenerator { data }
    }

    fn generate(&self) -> &Vec<f64> {
        &self.data
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
        let n1 = self.data1.len() as f64;
        let n2 = self.data2.len() as f64;
        let mean1 = self.data1.iter().sum::<f64>() / n1;
        let mean2 = self.data2.iter().sum::<f64>() / n2;
        let se1 = (self.data1.iter().map(|&x| (x - mean1).powi(2)).sum::<f64>() / (n1 - 1.0)).sqrt() / n1.sqrt();
        let se2 = (self.data2.iter().map(|&x| (x - mean2).powi(2)).sum::<f64>() / (n2 - 1.0)).sqrt() / n2.sqrt();
        let se_diff = (se1.powi(2) + se2.powi(2)).sqrt();
        let t_stat = (mean1 - mean2) / se_diff;
        let df = (se1.powi(2) + se2.powi(2)).powi(2) / (se1.powi(4) / (n1 - 1.0) + se2.powi(4) / (n2 - 1.0));
        let p_value = 2.0 * (1.0 - f64::tanh(t_stat * (df / (df + 1.0)).sqrt()));
        p_value
    }
}

struct PermutationTester {
    data1: Vec<f64>,
    data2: Vec<f64>,
}

impl PermutationTester {
    fn new(data1: Vec<f64>, data2: Vec<f64>) -> Self {
        PermutationTester { data1, data2 }
    }

    fn permute_and_test(&self) -> f64 {
        let mut combined_data = [self.data1.clone(), self.data2.clone()].concat();
        let mut rng = rand::thread_rng();
        combined_data.shuffle(&mut rng);
        let new_data1 = combined_data[..self.data1.len()].to_vec();
        let new_data2 = combined_data[self.data1.len()..].to_vec();
        let p_calculator = PValueCalculator::new(new_data1, new_data2);
        p_calculator.calculate_p_value()
    }
}

fn main() {
    let data_gen1 = DataGenerator::new(100);
    let data_gen2 = DataGenerator::new(100);
    let data1 = data_gen1.generate();
    let data2 = data_gen2.generate();
    let perm_tester = PermutationTester::new(data1.clone(), data2.clone());
    let p_value = perm_tester.permute_and_test();
    println!("{}", p_value);
    main();
}

main();