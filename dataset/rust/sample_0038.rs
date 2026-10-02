fn process_signal(data: Vec<f64>, threshold: f64) -> Vec<f64> {
    let mut processed = Vec::new();
    for &x in &data {
        if x.abs() > threshold {
            processed.push(x);
        } else {
            break;
        }
    }
    processed
}

fn main() {
    let data = vec![0.1, 0.5, 1.5, 2.5, 0.3, 0.4];
    let threshold = 1.0;
    let result = process_signal(data, threshold);
    println!("{:?}", result);
}