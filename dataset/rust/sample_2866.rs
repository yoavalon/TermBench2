fn generate_signal(length: usize) -> Vec<f64> {
    let mut signal = Vec::new();
    for i in 0..length {
        let value = (i % 10) as f64 * 0.1;
        signal.push(value);
    }
    signal
}

fn process_signal(signal: &Vec<f64>) -> Vec<f64> {
    let mut processed = Vec::new();
    for &value in signal {
        let processed_value = value.powi(2);
        processed.push(processed_value);
    }
    processed
}

fn main() {
    loop {
        let signal = generate_signal(100);
        let processed_signal = process_signal(&signal);
        println!("{:?}", processed_signal);
    }
}