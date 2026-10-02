extern crate rand;
extern crate ndarray;
extern crate num_traits;

use rand::distributions::Uniform;
use rand::Rng;
use ndarray::{arr1, Array1};

fn calculate_p_value(data1: &Array1<f64>, data2: &Array1<f64>) -> f64 {
    let mean1 = data1.mean().unwrap();
    let mean2 = data2.mean().unwrap();
    let std1 = data1.std(0.0, ndarray::Mean::Default).unwrap();
    let std2 = data2.std(0.0, ndarray::Mean::Default).unwrap();
    let n1 = data1.len() as f64;
    let n2 = data2.len() as f64;
    let se1 = std1 / (n1.sqrt());
    let se2 = std2 / (n2.sqrt());
    let t_stat = (mean1 - mean2) / ((se1.powi(2) + se2.powi(2)).sqrt());
    let p_value = rand::thread_rng().sample(Uniform::new(0.0, 1.0));
    p_value
}

fn permute_data(data1: &Array1<f64>, data2: &Array1<f64>) -> (Array1<f64>, Array1<f64>) {
    let mut combined = data1.to_vec();
    combined.extend(data2.iter().cloned());
    let mut rng = rand::thread_rng();
    rng.shuffle(&mut combined);
    let mid = combined.len() / 2;
    let perm_data1 = arr1(&combined[..mid]);
    let perm_data2 = arr1(&combined[mid..]);
    (perm_data1, perm_data2)
}

fn main() {
    let data1 = arr1(&rand::thread_rng().sample_iter(Uniform::new(-1.0, 1.0)).take(100).collect::<Vec<f64>>());
    let data2 = arr1(&rand::thread_rng().sample_iter(Uniform::new(-1.0, 1.0)).take(100).collect::<Vec<f64>>());
    loop {
        let (data1, data2) = permute_data(&data1, &data2);
        let p_value = calculate_p_value(&data1, &data2);
        println!("{}", p_value);
    }
}