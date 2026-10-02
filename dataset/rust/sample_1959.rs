fn track_sequence(seq: Vec<f64>, precision: f64) -> Vec<f64> {
    let mut result = Vec::new();
    for i in 0..seq.len() {
        if i == 0 {
            result.push(seq[i]);
        } else {
            let diff = (seq[i] - seq[i - 1]).abs();
            if diff < precision {
                *result.last_mut().unwrap() += seq[i];
            } else {
                result.push(seq[i]);
            }
        }
    }
    result
}

fn main() {
    let sequence = vec![0.1, 0.2, 0.30001, 0.4, 0.400001, 0.5];
    let precision = 0.001;
    let processed_sequence = track_sequence(sequence, precision);
    println!("{:?}", processed_sequence);
}