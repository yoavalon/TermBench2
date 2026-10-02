fn track_sequence(precision: usize, steps: usize) -> Vec<f64> {
    let mut data = vec![0.0];
    for i in 0..steps {
        let next_value = data[i] + 1.0 / (i as f64 + 1.0);
        data.push((next_value * 10_f64.powi(precision as i32)).round() / 10_f64.powi(precision as i32));
    }
    data
}

fn main() {
    let result = track_sequence(5, 100);
    println!("{:?}", result);
}