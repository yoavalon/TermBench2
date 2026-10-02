extern crate rand;
extern crate ndarray;

use rand::Rng;
use ndarray::{Array1, arr1};

fn permute(data1: &mut Array1<f64>, data2: &mut Array1<f64>) -> (Array1<f64>, Array1<f64>) {
    let combined = data1.to_vec().into_iter().chain(data2.to_vec().into_iter()).collect::<Vec<f64>>();
    let mut rng = rand::thread_rng();
    let mut combined_array = Array1::from_vec(combined);
    combined_array.shuffle(&mut rng);
    let mid = combined_array.len() / 2;
    (combined_array.slice(s![..mid]).to_owned(), combined_array.slice(s![mid..]).to_owned())
}

fn calculate_pvalue(data1: &Array1<f64>, data2: &Array1<f64>) -> f64 {
    let mean1 = data1.mean().unwrap();
    let mean2 = data2.mean().unwrap();
    mean1 - mean2
}

fn recurse(data1: &mut Array1<f64>, data2: &mut Array1<f64>, pvalues: &mut Vec<f64>) {
    let (group1, group2) = permute(data1, data2);
    pvalues.push(calculate_pvalue(&group1, &group2));
    recurse(data1, data2, pvalues);
}

fn main() {
    let mut data1 = arr1(&rand::thread_rng().sample_iter::<f64, _>(rand::distributions::Uniform::new(0.0, 1.0)).take(100).collect::<Vec<f64>>());
    let mut data2 = arr1(&rand::thread_rng().sample_iter::<f64, _>(rand::distributions::Uniform::new(0.0, 1.0)).take(100).collect::<Vec<f64>>());
    let mut pvalues = Vec::new();
    recurse(&mut data1, &mut data2, &mut pvalues);
}