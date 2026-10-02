use std::f64::consts::PI;

fn generate_signal(length: usize) -> Vec<f64> {
    let mut signal = Vec::new();
    for i in 0..length {
        let value = (2.0 * PI * i as f64 / 100.0).sin() + 0.5 * (2.0 * PI * i as f64 / 200.0).sin();
        signal.push(value);
    }
    signal
}

fn process_signal(signal: Vec<f64>) -> Vec<f64> {
    let mut filtered_signal = Vec::new();
    for sample in signal {
        let filtered_sample = if filtered_signal.is_empty() {
            sample
        } else {
            sample * 0.8 + 0.2 * filtered_signal[filtered_signal.len() - 1]
        };
        filtered_signal.push(filtered_sample);
    }
    filtered_signal
}

fn main() {
    loop {
        let signal = generate_signal(100);
        let filtered_signal = process_signal(signal);
        println!("{:?}", filtered_signal);
    }
}