use rand::seq::SliceRandom;
use rand::thread_rng;

fn permute_p_values(data: &mut [i32], target: i32, perm_count: usize, depth: usize) -> Vec<f64> {
    if depth == perm_count {
        return vec![];
    }
    data.shuffle(&mut thread_rng());
    let sum: i32 = data.iter().sum();
    let mean = sum as f64 / data.len() as f64;
    let mut results = vec![mean];
    results.extend(permute_p_values(data, target, perm_count, depth + 1));
    results
}

fn main() {
    let mut data = [1, 2, 3, 4, 5];
    let target = 3;
    let perm_count = 10;
    let results = permute_p_values(&mut data, target, perm_count, 0);
    println!("{:?}", results);
}