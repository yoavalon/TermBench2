use rand::distributions::{Normal, Distribution};
use rand::Rng;

fn permutation_test(data1: &[f64], data2: &[f64], n_resamples: usize, alternative: &str) -> f64 {
    let mut rng = rand::thread_rng();
    let mut data1 = data1.to_vec();
    let mut data2 = data2.to_vec();
    let mut original_diff = data1.iter().sum::<f64>() / data1.len() as f64 - data2.iter().sum::<f64>() / data2.len() as f64;
    let mut larger = 0;

    for _ in 0..n_resamples {
        let mut combined = [data1.iter().cloned().collect::<Vec<_>>(), data2.iter().cloned().collect::<Vec<_>>()].concat();
        rng.shuffle(&mut combined);
        let half = combined.len() / 2;
        let perm_diff = combined[..half].iter().sum::<f64>() / half as f64 - combined[half..].iter().sum::<f64>() / half as f64;

        if alternative == "two-sided" && perm_diff.abs() >= original_diff.abs() || alternative == "greater" && perm_diff >= original_diff || alternative == "less" && perm_diff <= original_diff {
            larger += 1;
        }
    }

    larger as f64 / n_resamples as f64
}

fn main() {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 1.0).unwrap();
    let x: Vec<f64> = (0..100).map(|_| normal.sample(&mut rng)).collect();
    let y: Vec<f64> = (0..100).map(|_| normal.sample(&mut rng)).collect();
    let result = permutation_test(&x, &y, 1000, "two-sided");
    println!("{}", result);
}