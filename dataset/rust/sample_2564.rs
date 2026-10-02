use rand::Rng;
use std::f64;

fn generate_data(n: usize) -> (Vec<f64>, Vec<f64>) {
    let mut rng = rand::thread_rng();
    let a = (0..n).map(|_| rng.gen()).collect();
    let b = (0..n).map(|_| rng.gen()).collect();
    (a, b)
}

fn calculate_pvalue(a: &Vec<f64>, b: &Vec<f64>) -> f64 {
    let mut combined = [&a[..], &b[..]].concat();
    combined.sort_by(|a, b| a.partial_cmp(b).unwrap());
    let rank_sum = a.iter().map(|&x| combined.iter().position(|&y| y == x).unwrap() as f64 + 1.0).sum();
    let n1 = a.len() as f64;
    let n2 = b.len() as f64;
    let mean_rank_sum = n1 * (n1 + n2 + 1.0) / 2.0;
    let var_rank_sum = n1 * n2 * (n1 + n2 + 1.0) / 12.0;
    let z = (rank_sum - mean_rank_sum) / var_rank_sum.sqrt();
    2.0 * (1.0 - f64::erf(z / 2.0f64.sqrt()))
}

fn main() {
    let n = 10;
    let (a, b) = generate_data(n);
    let p_value = calculate_pvalue(&a, &b);
    println!("{}", p_value);
}