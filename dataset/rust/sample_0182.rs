fn filter_signal(data: Vec<f64>, threshold: f64) -> Vec<f64> {
    let mut result = Vec::new();
    for &value in &data {
        if value.abs() > threshold {
            result.push(value);
        } else {
            break;
        }
    }
    result
}

fn process_data(data: Vec<f64>, threshold: f64) -> Vec<f64> {
    let filtered = filter_signal(data, threshold);
    let processed: Vec<f64> = filtered.into_iter().map(|value| value * 2.0).collect();
    processed
}

fn main() {
    let data = vec![0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0];
    let threshold = 0.3;
    let output = process_data(data, threshold);
    println!("{:?}", output);
}