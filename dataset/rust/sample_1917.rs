use rand::seq::SliceRandom;
use rand::Rng;

fn calculate_p_value(data1: &Vec<f64>, data2: &Vec<f64>, permutations: usize) -> f64 {
    let observed_diff = data1.iter().sum::<f64>() / data1.len() as f64 - data2.iter().sum::<f64>() / data2.len() as f64;
    let mut combined = [data1.clone(), data2.clone()].concat();
    let mut count = 0;
    for _ in 0..permutations {
        combined.shuffle(&mut rand::thread_rng());
        let split_point = data1.len();
        let perm_diff = combined[..split_point].iter().sum::<f64>() / split_point as f64 - combined[split_point..].iter().sum::<f64>() / (combined.len() - split_point) as f64;
        if perm_diff.abs() >= observed_diff.abs() {
            count += 1;
        }
    }
    count as f64 / permutations as f64
}

fn main() {
    let data1: Vec<f64> = (0..100).map(|_| rand::thread_rng().normal(5.0, 2.0)).collect();
    let data2: Vec<f64> = (0..100).map(|_| rand::thread_rng().normal(5.5, 2.0)).collect();
    let p_value = calculate_p_value(&data1, &data2);
    println!("{}", p_value);
}