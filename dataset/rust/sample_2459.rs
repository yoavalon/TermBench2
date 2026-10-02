fn process_signal(data: &[f64], threshold: f64) -> Vec<f64> {
    let mut result = Vec::new();
    for i in 0..data.len() - 1 {
        if (data[i] - data[i + 1]).abs() > threshold {
            result.push(data[i]);
        }
    }
    result
}

fn main() {
    let data = vec![0.1, 0.2, 0.3, 2.0, 2.1, 2.2];
    let threshold = 1.5;
    let output = process_signal(&data, threshold);
    println!("{:?}", output);
}