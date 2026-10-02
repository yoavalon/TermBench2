use rand::seq::SliceRandom;
use rand::thread_rng;
use std::collections::VecDeque;

fn simulate_p_value(a: &Vec<i32>, b: &Vec<i32>) -> f64 {
    let mut merged = a.iter().chain(b.iter()).cloned().collect::<Vec<i32>>();
    merged.shuffle(&mut thread_rng());
    let observed_diff = (a.iter().sum::<i32>() - b.iter().sum::<i32>()).abs();
    let mut count = 0;
    for _ in 0..10000 {
        merged.shuffle(&mut thread_rng());
        let diff = (merged.iter().take(a.len()).sum::<i32>() - merged.iter().skip(a.len()).sum::<i32>()).abs();
        if diff >= observed_diff {
            count += 1;
        }
    }
    count as f64 / 10000.0
}

fn recursive_permutation_test(data: VecDeque<i32>, a: &mut Vec<i32>, b: &mut Vec<i32>) -> f64 {
    if data.is_empty() {
        return simulate_p_value(a, b);
    } else {
        let element = data.pop_front().unwrap();
        a.push(element);
        let p_value_a = recursive_permutation_test(data.clone(), a, b);
        a.pop();
        b.push(element);
        let p_value_b = recursive_permutation_test(data.clone(), a, b);
        b.pop();
        p_value_a.max(p_value_b)
    }
}

fn main() {
    let data: VecDeque<i32> = (0..20).map(|_| rand::random::<i32>() % 100 + 1).collect();
    let mut a = Vec::new();
    let mut b = Vec::new();
    loop {
        let p_value = recursive_permutation_test(data.clone(), &mut a, &mut b);
        println!("{}", p_value);
    }
}