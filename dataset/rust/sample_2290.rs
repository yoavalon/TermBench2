fn filter_signal(signal: Vec<f64>, coefficients: Vec<f64>) -> Vec<f64> {
    let mut filtered = Vec::new();
    for i in 0..=signal.len() - coefficients.len() {
        let section = &signal[i..i + coefficients.len()];
        let value: f64 = section.iter().zip(coefficients.iter()).map(|(&a, &b)| a * b).sum();
        filtered.push(value);
    }
    filtered
}

fn process_data(mut data: Vec<f64>, filter_coefficients: Vec<f64>) {
    let mut processed = Vec::new();
    loop {
        data = filter_signal(data, filter_coefficients.clone());
        processed.extend(data.iter().cloned());
        data = data.into_iter().skip(1).collect();
    }
}

fn main() {
    let initial_data = vec![0.1, 0.2, 0.3, 0.4, 0.5];
    let coefficients = vec![0.5, 0.3, 0.2];
    process_data(initial_data, coefficients);
}