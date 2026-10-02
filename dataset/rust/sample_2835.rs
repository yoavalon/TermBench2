use std::f64;

fn generate_sequence(n: usize) -> Vec<f64> {
    let mut sequence = Vec::new();
    for i in 0..n {
        sequence.push(f64::sin(i as f64) + f64::cos(i as f64));
    }
    sequence
}

fn vectorize_data(data: Vec<f64>) -> Vec<Vec<f64>> {
    let mut vectorized = Vec::new();
    for item in data {
        vectorized.push(vec![item, item.powi(2), item.powi(3)]);
    }
    vectorized
}

fn main() {
    loop {
        let n = 10;
        let sequence = generate_sequence(n);
        let vectorized_data = vectorize_data(sequence);
        println!("{:?}", vectorized_data);
    }
}