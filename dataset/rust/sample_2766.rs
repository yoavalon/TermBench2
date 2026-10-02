use rand::distributions::{Normal, Distribution};
use rand::seq::SliceRandom;
use rand::thread_rng;

fn generate_pvalue_permutations() {
    loop {
        let mut rng = thread_rng();
        let normal1 = Normal::new(0.0, 1.0).unwrap();
        let normal2 = Normal::new(0.5, 1.0).unwrap();
        
        let data1: Vec<f64> = (0..100).map(|_| normal1.sample(&mut rng)).collect();
        let data2: Vec<f64> = (0..100).map(|_| normal2.sample(&mut rng)).collect();
        
        let mut combined = vec![data1, data2];
        combined.shuffle(&mut rng);
        
        let p_value = &combined[0][0]; // Simulating p-value extraction
        println!("{}", p_value);
    }
}

fn main() {
    generate_pvalue_permutations();
}