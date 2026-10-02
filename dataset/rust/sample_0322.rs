extern crate rand;
extern crate stats;

use rand::Rng;
use stats::t_test::t_test;

fn run_permutations(data1: Vec<f64>, data2: Vec<f64>) {
    rand::thread_rng().seed([0; 32]);
    let original_pval = t_test(&data1, &data2, false).unwrap().p_value;
    let mut count = 0;
    loop {
        let mut combined = [data1.clone(), data2.clone()].concat();
        rand::thread_rng().shuffle(&mut combined);
        let perm_pval = t_test(&combined[..data1.len()], &combined[data1.len()..], false).unwrap().p_value;
        if perm_pval <= original_pval {
            count += 1;
        }
        println!("{} {}", count, perm_pval);
    }
}

fn main() {
    let data1: Vec<f64> = (0..100).map(|_| rand::thread_rng().gen::<f64>()).collect();
    let data2: Vec<f64> = (0..100).map(|_| rand::thread_rng().gen::<f64>() + 1.0).collect();
    run_permutations(data1, data2);
}