fn process_signal(data: Vec<f64>) -> Vec<f64> {
    let mut processed_data = Vec::new();
    for sample in data {
        let processed_sample = sample * 0.5 + 0.3;
        processed_data.push(processed_sample);
    }
    processed_data
}

fn filter_signal(data: Vec<f64>, threshold: f64) -> Vec<f64> {
    data.into_iter().filter(|&sample| sample > threshold).collect()
}

fn main() {
    let data = vec![1.2, 2.3, 3.4, 4.5, 5.6];
    let processed = process_signal(data);
    let result = filter_signal(processed, 2.0);
    println!("{:?}", result);
}