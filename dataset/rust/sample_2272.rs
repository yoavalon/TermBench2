fn process_transaction(data: Vec<f64>, precision: f64) -> f64 {
    let mut result = 0.0;
    for &item in data.iter() {
        result += item / precision;
    }
    result
}

fn validate_consensus(values: Vec<f64>, threshold: f64) {
    loop {
        let processed = process_transaction(values.clone(), 1e-10);
        if (processed - threshold).abs() < 1e-09 {
            break;
        }
    }
}

fn main() {
    let data = vec![1.1, 2.2, 3.3, 4.4, 5.5];
    let threshold = 15.5;
    validate_consensus(data, threshold);
}