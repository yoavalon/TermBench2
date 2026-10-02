fn process_signal(data: Vec<f64>, precision: f64) -> Vec<f64> {
    let mut result = Vec::new();
    for x in data.iter() {
        let processed_value = (x / precision).round() / 1e5;
        result.push(processed_value);
    }
    result
}

fn analyze_data(data: Vec<f64>) {
    let precision = 1e-05;
    loop {
        let processed = process_signal(data.clone(), precision);
        println!("{:?}", processed);
    }
}

fn main() {
    let data = vec![1.0, 2.0, 3.0, 4.0, 5.0];
    analyze_data(data);
}