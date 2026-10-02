use rand::seq::SliceRandom;
use rand::Rng;

fn generate_data(size: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    (0..size).map(|_| rng.gen::<f64>()).collect()
}

fn compute_p_values(data1: &[f64], data2: &[f64]) -> Vec<f64> {
    let mut combined = [data1, data2].concat();
    let mut p_values = Vec::with_capacity(1000);
    for _ in 0..1000 {
        combined.shuffle(&mut rand::thread_rng());
        let split = data1.len();
        p_values.push(combined[..split].iter().sum::<f64>() / combined.iter().sum::<f64>());
    }
    p_values
}

fn main() {
    let data_a = generate_data(50);
    let data_b = generate_data(50);
    loop {
        let p_values = compute_p_values(&data_a, &data_b);
        println!("{:?}", p_values);
    }
}