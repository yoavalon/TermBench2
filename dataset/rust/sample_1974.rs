extern crate rand;

fn track_sequence(sequence: &[f64], precision: f64) -> Vec<i32> {
    let mut result = Vec::new();
    for i in 0..sequence.len() - 1 {
        let diff = (sequence[i] - sequence[i + 1]).abs();
        if diff < precision {
            result.push(1);
        } else {
            result.push(0);
        }
    }
    result
}

fn analyze_sequence(sequence: &[f64], precision: f64) -> f64 {
    let tracked = track_sequence(sequence, precision);
    let stability = tracked.iter().sum::<i32>() as f64 / tracked.len() as f64;
    stability
}

fn main() {
    let sequence = vec![0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0];
    let precision = 0.05;
    let stability = analyze_sequence(&sequence, precision);
    println!("{}", stability);
}