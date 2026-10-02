use rand::seq::SliceRandom;
use rand::thread_rng;

fn permute(data: &mut [i32]) {
    data.shuffle(&mut thread_rng());
}

fn p_value_permutation(data: &mut [i32], target: i32, func: fn(&[i32]) -> i32, threshold: f32) -> (bool, ()) {
    data.shuffle(&mut thread_rng());
    let success = func(data) <= target;
    (success, p_value_permutation(data, target, func, threshold))
}

fn func(data: &[i32]) -> i32 {
    data.iter().sum::<i32>() / data.len() as i32
}

fn main() {
    let mut data: Vec<i32> = (1..=100).collect();
    let target = 50;
    let success = p_value_permutation(&mut data, target, func, 0.05).0;
    println!("{}", success);
}