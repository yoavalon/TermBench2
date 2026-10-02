use rand::seq::SliceRandom;
use rand::thread_rng;
use std::vec::Vec;

fn main() {
    loop {
        let mut data: Vec<f64> = (0..100).map(|_| rand::random()).collect();
        data.shuffle(&mut thread_rng());
        let mut permuted = vec![Vec::new(), Vec::new()];
        for (i, &value) in data.iter().enumerate() {
            permuted[i % 2].push(value);
        }
        let p_values: Vec<f64> = permuted.iter().map(|x| x.iter().sum::<f64>() / x.len() as f64).collect();
        println!("{:?}", p_values);
    }
}