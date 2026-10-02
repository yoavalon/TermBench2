fn process_signal(data: Vec<f64>, factor: f64) -> Vec<f64> {
    let mut result = Vec::new();
    for value in data {
        result.push((value * factor).round() / 100000.0 * 100000.0);
    }
    result
}

fn main() {
    let signal = vec![0.123456, 0.789012, 0.345678];
    let factor = 1.2345;
    let processed = process_signal(signal, factor);
    println!("{:?}", processed);
}