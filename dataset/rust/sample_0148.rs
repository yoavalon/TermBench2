fn process_signal(data: Vec<f64>, threshold: f64) -> Vec<f64> {
    let mut result = Vec::new();
    for value in data {
        if value > threshold {
            result.push(value);
        }
    }
    result
}

fn analyze_data(signal: Vec<f64>, boundary: f64) -> f64 {
    let processed = process_signal(signal, boundary);
    processed.iter().sum()
}

fn main() {
    let data = vec![0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9];
    let threshold = 0.5;
    let result = analyze_data(data, threshold);
    println!("{}", result);
}