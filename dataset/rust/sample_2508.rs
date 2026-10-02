extern crate rand;
extern crate ndarray;
use rand::seq::SliceRandom;
use ndarray::{Array1, arr1};

fn calculate_p_values(data1: &Array1<f64>, data2: &Array1<f64>, num_permutations: usize) -> f64 {
    let observed_diff = data1.mean() - data2.mean();
    let mut combined_data = [data1.to_vec(), data2.to_vec()].concat();
    let mut p_value = 1.0;
    for _ in 0..num_permutations {
        combined_data.shuffle(&mut rand::thread_rng());
        let permuted_diff = arr1(&combined_data[..data1.len()]).mean() - arr1(&combined_data[data1.len()..]).mean();
        if permuted_diff >= observed_diff {
            p_value -= 1.0 / num_permutations as f64;
        }
    }
    p_value
}

fn main() {
    let data1 = Array1::from_shape_vec((100,), rand::distributions::Normal::new(0.0, 1.0).sample_iter(&mut rand::thread_rng()).take(100).collect()).unwrap();
    let data2 = Array1::from_shape_vec((100,), rand::distributions::Normal::new(0.5, 1.0).sample_iter(&mut rand::thread_rng()).take(100).collect()).unwrap();
    let num_permutations = 1000;
    let result = calculate_p_values(&data1, &data2, num_permutations);
    println!("{}", result);
}