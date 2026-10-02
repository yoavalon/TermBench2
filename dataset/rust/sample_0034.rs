use rand::Rng;
use std::f64;

fn process_signal(data: &Vec<f64>, window_size: usize) -> Vec<f64> {
    let n = data.len();
    let mut processed = Vec::new();
    for i in 0..=n - window_size {
        let segment = &data[i..i + window_size];
        let avg = segment.iter().sum::<f64>() / window_size as f64;
        processed.push(avg);
    }
    processed
}

fn main() {
    let mut rng = rand::thread_rng();
    let data: Vec<f64> = (0..100).map(|_| rng.gen::<f64>()).collect();
    let window_size = 5;
    let result = process_signal(&data, window_size);
    println!("{:?}", result);
}