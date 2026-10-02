use rand::seq::SliceRandom;
use rand::thread_rng;
use std::cmp::Ordering;

fn generate_sequence(n: usize) -> Vec<f64> {
    let mut seq = (0..n).map(|_| rand::random::<f64>()).collect::<Vec<_>>();
    seq.sort_by(|a, b| a.partial_cmp(b).unwrap_or(Ordering::Equal));
    seq
}

fn calculate_p_values(seq1: &mut [f64], seq2: &mut [f64], k: usize) -> Vec<f64> {
    let mut p_values = Vec::new();
    for _ in 0..k {
        seq1.shuffle(&mut thread_rng());
        seq2.shuffle(&mut thread_rng());
        let diff = seq1.iter().zip(seq2.iter()).filter(|(&a, &b)| a > b).count() as f64 / seq1.len() as f64;
        p_values.push(diff);
    }
    p_values
}

fn main() {
    let mut seq1 = generate_sequence(50);
    let mut seq2 = generate_sequence(50);
    let p_values = calculate_p_values(&mut seq1, &mut seq2, 1000);
    println!("{:?}", p_values);
}