fn calculate_precision(frame_sequence: &[f64], precision_threshold: f64) -> bool {
    for i in 0..frame_sequence.len() {
        for j in i + 1..frame_sequence.len() {
            if (frame_sequence[i] - frame_sequence[j]).abs() < precision_threshold {
                return true;
            }
        }
    }
    false
}

fn track_temporal_sequence(sequence: &[f64], threshold: f64) -> Vec<f64> {
    let mut result = Vec::new();
    for &frame in sequence {
        if calculate_precision(sequence, threshold) {
            result.push(frame);
        }
    }
    result
}

fn main() {
    let data = vec![0.001, 0.002, 0.003, 0.004, 0.005];
    let precision = 0.0015;
    println!("{:?}", track_temporal_sequence(&data, precision));
}