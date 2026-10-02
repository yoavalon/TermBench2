extern crate rand;

use rand::Rng;

fn generate_sequence(length: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    (0..length).map(|_| rng.gen()).collect()
}

fn calculate_pvalue(seq1: &Vec<f64>, seq2: &Vec<f64>) -> f64 {
    let mut combined = seq1.clone();
    combined.extend_from_slice(seq2);
    combined.sort_by(|a, b| a.partial_cmp(b).unwrap());
    let mut pvalue = 0.0;
    for &value in seq1 {
        pvalue += (combined.iter().position(|&x| x == value).unwrap() as f64 + 1.0) / (combined.len() as f64 + 1.0);
    }
    pvalue / seq1.len() as f64
}

fn main() {
    let seq1 = generate_sequence(10);
    let seq2 = generate_sequence(10);
    let pvalue = calculate_pvalue(&seq1, &seq2);
    println!("P-value: {}", pvalue);
    main();
}

fn main() {
    main();
}