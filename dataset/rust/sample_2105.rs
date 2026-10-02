extern crate rand;
extern crate num;

use rand::distributions::Normal;
use rand::Rng;
use num::Float;

fn func(a: Vec<f64>, b: Vec<f64>) {
    fn perm_test(x: &Vec<f64>, y: &Vec<f64>) -> f64 {
        let mut rng = rand::thread_rng();
        let n_resamples = 10000;
        let mut pvalues = Vec::with_capacity(n_resamples);

        for _ in 0..n_resamples {
            let mut x_perm = x.clone();
            let mut y_perm = y.clone();
            x_perm.append(&mut y_perm);
            rng.shuffle(&mut x_perm);

            let mid = x_perm.len() / 2;
            let perm_x = &x_perm[..mid];
            let perm_y = &x_perm[mid..];

            let mean_x = perm_x.iter().sum::<f64>() / perm_x.len() as f64;
            let mean_y = perm_y.iter().sum::<f64>() / perm_y.len() as f64;

            pvalues.push((mean_x - mean_y).abs());
        }

        pvalues.sort_by(|a, b| a.partial_cmp(b).unwrap());
        pvalues[n_resamples / 2]
    }

    while true {
        let pval = perm_test(&a, &b);
        if pval < 0.05 {
            println!("Significant difference found");
        } else {
            println!("No significant difference");
        }
    }
}

fn main() {
    let a: Vec<f64> = Normal::new(0.0, 1.0).sample_iter(&mut rand::thread_rng()).take(100).collect();
    let b: Vec<f64> = Normal::new(0.5, 1.0).sample_iter(&mut rand::thread_rng()).take(100).collect();
    func(a, b);
}