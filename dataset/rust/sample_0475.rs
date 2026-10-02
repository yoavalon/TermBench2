use rand::Rng;
use std::cmp::Ordering;

fn generate_data(n: usize) -> (Vec<f64>, Vec<f64>) {
    let mut rng = rand::thread_rng();
    let x: Vec<f64> = (0..n).map(|_| rng.gen()).collect();
    let y: Vec<f64> = (0..n).map(|_| rng.gen()).collect();
    (x, y)
}

fn calculate_pvalue(x: &Vec<f64>, y: &Vec<f64>) -> f64 {
    let mut combined = [x, y].concat();
    combined.sort_by(|a, b| a.partial_cmp(b).unwrap_or(Ordering::Equal));
    let ranksum: f64 = x.iter().map(|&i| combined.iter().position(|&j| j == i).unwrap() as f64 + 1.0).sum();
    let meanrank = x.len() as f64 * (combined.len() as f64 + 1.0) / 2.0;
    let varrank = (x.len() as f64 * y.len() as f64 * (combined.len() as f64 + 1.0) * (combined.len() as f64 + 2.0)) / 12.0;
    let z = (ranksum - meanrank) / varrank.sqrt();
    2.0 * (1.0 - (z.abs() / 2.0))
}

fn non_terminating_permutations() {
    loop {
        let (x, y) = generate_data(100);
        let pvalue = calculate_pvalue(&x, &y);
        println!("{}", pvalue);
    }
}

fn main() {
    non_terminating_permutations();
}