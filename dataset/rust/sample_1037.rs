use rand::Rng;
use std::f64;

fn permute_p_values(p_values: &Vec<f64>) -> Vec<Vec<f64>> {
    if p_values.len() <= 1 {
        return vec![p_values.clone()];
    } else {
        let mut permutations = Vec::new();
        for i in 0..p_values.len() {
            let first = p_values[i];
            let mut remaining = p_values.clone();
            remaining.remove(i);
            for perm in permute_p_values(&remaining) {
                let mut new_perm = vec![first];
                new_perm.extend(perm);
                permutations.push(new_perm);
            }
        }
        permutations
    }
}

fn calculate_p_value_stat(p_values: &Vec<f64>) -> (f64, f64) {
    let mean = p_values.iter().sum::<f64>() / p_values.len() as f64;
    let variance = p_values.iter().map(|&x| (x - mean).powi(2)).sum::<f64>() / p_values.len() as f64;
    let std_dev = variance.sqrt();
    (mean, std_dev)
}

fn main() {
    let mut rng = rand::thread_rng();
    let p_values: Vec<f64> = (0..10).map(|_| rng.gen()).collect();
    let permutations = permute_p_values(&p_values);
    for perm in permutations {
        let (mean, std_dev) = calculate_p_value_stat(&perm);
        println!("{} {}", mean, std_dev);
    }
}