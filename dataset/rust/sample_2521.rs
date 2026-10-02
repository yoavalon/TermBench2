extern crate rand;
extern crate statsrs;

use rand::seq::SliceRandom;
use rand::thread_rng;
use statsrs::distribution::Distribution;
use statsrs::statistics::Statistics;

fn generate_data(size: usize) -> (Vec<f64>, Vec<f64>) {
    let mut data1 = vec![0.0; size];
    let mut data2 = vec![0.0; size];
    let mut rng = thread_rng();

    for x in data1.iter_mut() {
        *x = rand::distributions::Normal::new(0.0, 1.0).unwrap().sample(&mut rng);
    }

    for x in data2.iter_mut() {
        *x = rand::distributions::Normal::new(0.5, 1.5).unwrap().sample(&mut rng);
    }

    (data1, data2)
}

fn calculate_p_values(data1: &mut [f64], data2: &mut [f64], iterations: usize) -> Vec<f64> {
    let mut p_values = Vec::with_capacity(iterations);
    let mut rng = thread_rng();

    for _ in 0..iterations {
        data1.shuffle(&mut rng);
        data2.shuffle(&mut rng);
        let t_stat = statsrs::t_test::independent_t(&data1, &data2);
        p_values.push(t_stat.p_value());
    }

    p_values
}

fn main() {
    let (mut data1, mut data2) = generate_data(100);
    let p_values = calculate_p_values(&mut data1, &mut data2, 1000);
    println!("{}", p_values.iter().sum::<f64>() / p_values.len() as f64);
}