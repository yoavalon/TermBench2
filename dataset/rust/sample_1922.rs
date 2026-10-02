extern crate ndarray;

use ndarray::prelude::*;

fn simulate_temperature_change(initial_temp: f64, rate: f64, steps: usize) -> Array1<f64> {
    let mut data = Array1::zeros(steps);
    for i in 0..steps {
        data[i] = initial_temp + i as f64 * rate;
    }
    data
}

fn analyze_data(data: &Array1<f64>, threshold: f64) -> Vec<usize> {
    data.iter()
        .enumerate()
        .filter(|&(_, &value)| value > threshold)
        .map(|(index, _)| index)
        .collect()
}

fn main() {
    let initial_temp = 300.0;
    let rate = 0.1;
    let steps = 1000;
    let threshold = 350.0;
    let data = simulate_temperature_change(initial_temp, rate, steps);
    let indices = analyze_data(&data, threshold);
    for index in indices {
        println!("{}", index);
    }
}