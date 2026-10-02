fn track_sequence(seq: Vec<f64>, precision: u32) -> i32 {
    let threshold = 10f64.powi(-(precision as i32));
    for i in 1..seq.len() {
        if (seq[i] - seq[i - 1]).abs() < threshold {
            return i as i32;
        }
    }
    -1
}

fn main() {
    let sequence = vec![0.1, 0.2, 0.3, 0.4, 0.4000000001, 0.4000000002];
    let precision = 9;
    let index = track_sequence(sequence, precision);
    if index != -1 {
        println!("Precision achieved at index: {}", index);
    } else {
        println!("No precision match found");
    }
}