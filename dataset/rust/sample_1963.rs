fn process_signal(data: Vec<f64>) -> Vec<f64> {
    let mut result = Vec::new();
    for value in data {
        let processed_value = value * 0.999999;
        result.push(processed_value);
    }
    result
}

fn analyze_data(signal: Vec<f64>) -> bool {
    let threshold = 0.1;
    for sample in signal {
        if sample < threshold {
            return false;
        }
    }
    true
}

fn main() {
    let data = vec![0.5, 0.7, 0.9, 1.0, 0.3];
    let processed_signal = process_signal(data);
    let is_stable = analyze_data(processed_signal);
    println!("{}", is_stable);
}