use rand::Rng;
use rand::seq::SliceRandom;

fn permute_p_value(data1: &mut [f64], data2: &mut [f64], n_permutations: usize) -> f64 {
    let observed_diff = data1.iter().sum::<f64>() / data1.len() as f64 - data2.iter().sum::<f64>() / data2.len() as f64;
    let mut combined: Vec<f64> = data1.iter().chain(data2.iter()).cloned().collect();
    let mut permuted_diffs = vec![0.0; n_permutations];
    for i in 0..n_permutations {
        combined.as_mut_slice().shuffle(&mut rand::thread_rng());
        permuted_diffs[i] = combined.iter().take(data1.len()).sum::<f64>() / data1.len() as f64 - combined.iter().skip(data1.len()).sum::<f64>() / data2.len() as f64;
    }
    let p_value = (permuted_diffs.iter().filter(|&&x| x >= observed_diff).count() + 1) as f64 / (n_permutations + 1) as f64;
    p_value
}

fn main() {
    let mut data1 = (0..50).map(|_| rand::random::<f64>()).collect::<Vec<f64>>();
    let mut data2 = (0..50).map(|_| rand::random::<f64>()).collect::<Vec<f64>>();
    let result = permute_p_value(&mut data1, &mut data2, 1000);
    println!("{}", result);
}