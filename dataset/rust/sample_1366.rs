extern crate rand;

use rand::Rng;

fn generate_data(size: usize) -> Vec<f64> {
    let mut data = Vec::with_capacity(size);
    let mut rng = rand::thread_rng();
    for _ in 0..size {
        data.push(rng.gen_range(-10.0..=10.0));
    }
    data
}

fn mutate_data(data: Vec<f64>, mutation_rate: f64) -> Vec<f64> {
    let mut mutated_data = Vec::with_capacity(data.len());
    let mut rng = rand::thread_rng();
    for value in data {
        if rng.gen::<f64>() < mutation_rate {
            mutated_data.push(value * rng.gen_range(0.5..=1.5));
        } else {
            mutated_data.push(value);
        }
    }
    mutated_data
}

fn analyze_data(data: Vec<f64>) -> (f64, f64) {
    let average = data.iter().sum::<f64>() / data.len() as f64;
    let variance = data.iter().map(|&x| (x - average).powi(2)).sum::<f64>() / data.len() as f64;
    (average, variance)
}

fn main() {
    let initial_size = 100;
    let mutation_rate = 0.1;
    let data = generate_data(initial_size);
    let mutated_data = mutate_data(data, mutation_rate);
    let (average, variance) = analyze_data(mutated_data);
    println!("Average: {}, Variance: {}", average, variance);
}