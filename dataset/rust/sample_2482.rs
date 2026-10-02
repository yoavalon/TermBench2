use rand::seq::SliceRandom;
use rand::Rng;
use std::iter::repeat_with;

fn ttest_ind(x: &[f64], y: &[f64]) -> f64 {
    let mean_x = x.iter().sum::<f64>() / x.len() as f64;
    let mean_y = y.iter().sum::<f64>() / y.len() as f64;
    let var_x = x.iter().map(|&val| (val - mean_x).powi(2)).sum::<f64>() / x.len() as f64;
    let var_y = y.iter().map(|&val| (val - mean_y).powi(2)).sum::<f64>() / y.len() as f64;
    let se = (var_x / x.len() as f64 + var_y / y.len() as f64).sqrt();
    (mean_x - mean_y).abs() / se
}

fn permute_p_value(x: &[f64], y: &[f64], n_permutations: usize) -> f64 {
    let observed_diff = x.iter().sum::<f64>() / x.len() as f64 - y.iter().sum::<f64>() / y.len() as f64;
    let mut combined: Vec<f64> = x.iter().cloned().chain(y.iter().cloned()).collect();
    let mut rng = rand::thread_rng();
    let p_values: Vec<f64> = repeat_with(|| {
        let perm_x: Vec<f64> = combined.choose_multiple(&mut rng, x.len()).cloned().collect();
        let perm_y: Vec<f64> = combined.choose_multiple(&mut rng, y.len()).cloned().collect();
        ttest_ind(&perm_x, &perm_y)
    })
    .take(n_permutations)
    .collect();
    p_values.iter().filter(|&&p| p <= observed_diff).count() as f64 / n_permutations as f64
}

fn main() {
    let x: Vec<f64> = (0..30).map(|_| rand::random::<f64>() * 2.0 - 1.0).collect();
    let y: Vec<f64> = (0..30).map(|_| rand::random::<f64>() * 2.0 - 0.5).collect();
    println!("{}", permute_p_value(&x, &y, 1000));
}