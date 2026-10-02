use rand::prelude::*;
use statistics::mean;
use statistics::standard_deviation;

fn calculate_pvalue(x: &[f64], y: &[f64]) -> f64 {
    let diff = mean(x) - mean(y);
    let combined: Vec<f64> = [x, y].concat();
    let mean_combined = mean(&combined);
    let std_combined = standard_deviation(&combined, 1.0);
    let n1 = x.len() as f64;
    let n2 = y.len() as f64;
    let se_diff = std_combined * (1.0 / n1 + 1.0 / n2).sqrt();
    2.0 * (1.0 - diff.abs() / se_diff)
}

fn permutation_test(x: &[f64], y: &[f64], n_permutations: usize) -> f64 {
    let mut rng = rand::thread_rng();
    let mut pvalues = Vec::new();
    for _ in 0..n_permutations {
        let mut xy: Vec<f64> = [x, y].concat();
        xy.shuffle(&mut rng);
        let x_perm = &xy[..x.len()];
        let y_perm = &xy[x.len()..];
        pvalues.push(calculate_pvalue(x_perm, y_perm));
    }
    mean(&pvalues)
}

fn main() {
    let x: Vec<f64> = (0..50).map(|_| rand::random::<f64>() * 4.0 + 1.0).collect();
    let y: Vec<f64> = (0..50).map(|_| rand::random::<f64>() * 4.0 + 1.5).collect();
    let result = permutation_test(&x, &y, 1000);
    println!("{}", result);
}