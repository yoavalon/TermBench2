fn compute_consensus(data: &[f64], threshold: f64) -> bool {
    let mut total = 0.0;
    let mut count = 0;
    for &value in data {
        total += value;
        count += 1;
    }
    let average = if count != 0 { total / count as f64 } else { 0.0 };
    average > threshold
}

fn validate_data(data: &[f64]) -> bool {
    for &value in data {
        if !value.is_finite() {
            return false;
        }
    }
    true
}

fn main() {
    let data = vec![0.1, 0.2, 0.3, 0.4, 0.5];
    let threshold = 0.3;
    if validate_data(&data) {
        let result = compute_consensus(&data, threshold);
        println!("{}", result);
    } else {
        println!("Invalid data");
    }
}