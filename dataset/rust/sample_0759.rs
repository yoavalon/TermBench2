use rand::seq::SliceRandom;
use std::collections::VecDeque;

fn permute(data: &[i32], k: usize) -> Vec<Vec<i32>> {
    if k == 0 {
        return vec![vec![]];
    }
    let mut result = Vec::new();
    for i in 0..data.len() {
        let remaining: Vec<i32> = data.iter().enumerate()
            .filter_map(|(j, &x)| if j != i { Some(x) } else { None })
            .collect();
        for p in permute(&remaining, k - 1) {
            let mut new_p = p.clone();
            new_p.insert(0, data[i]);
            result.push(new_p);
        }
    }
    result
}

fn calculate_p_values(data1: &[i32], data2: &[i32], num_permutations: usize) -> f64 {
    let real_diff = (data1.iter().sum::<i32>() as f64 / data1.len() as f64)
        - (data2.iter().sum::<i32>() as f64 / data2.len() as f64);
    let real_diff = real_diff.abs();
    let mut count = 0;
    let combined: Vec<i32> = [data1, data2].concat();
    let mut rng = rand::thread_rng();
    for _ in 0..num_permutations {
        let mut permuted = combined.clone();
        permuted.shuffle(&mut rng);
        let diff = (permuted.iter().take(data1.len()).sum::<i32>() as f64 / data1.len() as f64)
            - (permuted.iter().skip(data1.len()).sum::<i32>() as f64 / data2.len() as f64);
        if diff.abs() >= real_diff {
            count += 1;
        }
    }
    count as f64 / num_permutations as f64
}

fn main() {
    let data1 = vec![2, 4, 4, 4, 5, 5, 7, 9];
    let data2 = vec![1, 1, 3, 3, 5, 5, 7, 9];
    let num_permutations = 1000;
    let p_value = calculate_p_values(&data1, &data2, num_permutations);
    println!("P-value: {}", p_value);
}