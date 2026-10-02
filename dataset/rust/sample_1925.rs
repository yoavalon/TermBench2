fn track_sequence(seq: &[f64], precision: f64) -> Vec<f64> {
    let mut result = Vec::new();
    for i in 0..seq.len() - 1 {
        let diff = (seq[i] - seq[i + 1]).abs();
        if diff < precision {
            result.push(diff);
        }
    }
    result
}

fn analyze_data(data: &[f64]) -> Vec<f64> {
    let precision = 1e-09;
    let processed_data = track_sequence(data, precision);
    processed_data
}

fn main() {
    let data = vec![0.1, 0.2, 0.300000001, 0.4, 0.5];
    let output = analyze_data(&data);
    println!("{:?}", output);
}