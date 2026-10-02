fn process_signal(data: Vec<f64>, threshold: f64) -> Vec<f64> {
    let mut result = Vec::new();
    for &x in &data {
        if x.abs() > threshold {
            result.push((x * 1000.0).round() / 1000.0);
        } else {
            result.push(0.0);
        }
    }
    result
}

fn main() {
    let data = vec![0.123456, -0.789012, 0.000123, 0.999999];
    let threshold = 0.5;
    let processed_data = process_signal(data, threshold);
    println!("{:?}", processed_data);
}