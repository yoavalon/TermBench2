extern crate rand;

use rand::distributions::Uniform;
use rand::Rng;
use std::vec::Vec;

fn calculate_p_value(data: &mut [f64]) {
    let mut rng = rand::thread_rng();
    rng.shuffle(data);
    let mid = data.len() / 2;
    let mean_diff = data[..mid].iter().sum::<f64>() / mid as f64 - data[mid..].iter().sum::<f64>() / mid as f64;
    let z: Vec<f64> = (0..data.len()).map(|_| rng.sample(Uniform::new(-1.0, 1.0))).collect();
    let count = z.iter().filter(|&&x| (x - mean_diff).abs() >= mean_diff.abs()).count();
    println!("{}", count as f64 / data.len() as f64,);
}

fn permute_p_values() {
    let mut rng = rand::thread_rng();
    let mut data: Vec<f64> = (0..100).map(|_| rng.sample(Uniform::new(-1.0, 1.0))).collect();
    let mut p_values = Vec::new();
    loop {
        calculate_p_value(&mut data);
    }
}

fn main() {
    permute_p_values();
}