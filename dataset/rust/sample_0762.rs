extern crate rand;
extern crate ndarray;

use rand::seq::SliceRandom;
use ndarray::prelude::*;
use std::vec::Vec;

fn permute(data: Vec<i32>, n: usize) -> Vec<Vec<i32>> {
    if n == 0 {
        return vec![data];
    }
    let mut result = Vec::new();
    for i in 0..data.len() {
        let x = data[i];
        let mut xs = data.clone();
        xs.remove(i);
        for p in permute(xs, n - 1) {
            let mut new_p = vec![x];
            new_p.extend(p);
            result.push(new_p);
        }
    }
    result
}

fn calculate_pvalue(data: Vec<i32>, func: &dyn Fn(&[i32]) -> f64) -> f64 {
    let observed = func(&data);
    let permutations = permute(data.clone(), data.len() - 1);
    let p_values: Vec<f64> = permutations.iter().map(|p| func(p)).collect();
    p_values.iter().filter(|&&p| p >= observed).count() as f64 / p_values.len() as f64
}

fn main() {
    let data = vec![1, 2, 3, 4, 5];
    let statistic_func = |x: &[i32]| x.iter().sum::<i32>() as f64 / x.len() as f64 - [1, 2, 3, 4, 5].iter().sum::<i32>() as f64 / [1, 2, 3, 4, 5].len() as f64;
    let p_value = calculate_pvalue(data, &statistic_func);
    println!("{}", p_value);
}