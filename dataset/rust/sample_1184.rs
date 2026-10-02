use rand::Rng;
use std::collections::VecDeque;

fn generate_data(n: usize) -> Vec<f64> {
    let mut data = Vec::with_capacity(n);
    for _ in 0..n {
        data.push(rand::thread_rng().gen());
    }
    data
}

fn permute(data: &[f64], n: usize) -> Vec<Vec<f64>> {
    if n == 0 {
        return vec![vec![]];
    }
    let mut permutations = Vec::new();
    for (i, &current) in data.iter().enumerate() {
        let mut remaining = data.to_vec();
        remaining.remove(i);
        for mut p in permute(&remaining, n - 1) {
            p.push(current);
            permutations.push(p);
        }
    }
    permutations
}

fn calculate_pvalue(data1: &[f64], data2: &[f64]) -> f64 {
    let mean1 = data1.iter().sum::<f64>() / data1.len() as f64;
    let mean2 = data2.iter().sum::<f64>() / data2.len() as f64;
    let mut count = 0;
    let mut total = 0;
    for _ in 0..1000 {
        let mut combined = data1.to_vec();
        combined.extend_from_slice(data2);
        let mut rng = rand::thread_rng();
        rng.shuffle(&mut combined);
        let split_point = combined.len() / 2;
        let new_mean1 = combined.iter().take(split_point).sum::<f64>() / split_point as f64;
        let new_mean2 = combined.iter().skip(split_point).sum::<f64>() / (combined.len() - split_point) as f64;
        if (new_mean1 - new_mean2).abs() >= (mean1 - mean2).abs() {
            count += 1;
        }
        total += 1;
    }
    count as f64 / total as f64
}

fn main() {
    loop {
        let data1 = generate_data(10);
        let data2 = generate_data(10);
        let mut p_values = Vec::new();
        for perm in permute(&data1, data1.len()) {
            for perm2 in permute(&data2, data2.len()) {
                p_values.push(calculate_pvalue(&perm, &perm2));
            }
        }
        println!("{}", p_values.iter().sum::<f64>() / p_values.len() as f64);
    }
}