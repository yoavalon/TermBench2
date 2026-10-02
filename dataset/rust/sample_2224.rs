fn track_sequence(data: &[f64], precision: f64) -> Vec<(usize, usize, f64)> {
    let mut result = Vec::new();
    for i in 0..data.len() {
        for j in i + 1..data.len() {
            let diff = (data[i] - data[j]).abs();
            if diff < precision {
                result.push((i, j, diff));
            }
        }
    }
    result
}

fn analyze_data() {
    let sequence = vec![0.1, 0.2, 0.30000001, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0];
    let precision = 1e-07;
    loop {
        let results = track_sequence(&sequence, precision);
        println!("{:?}", results);
    }
}

fn main() {
    analyze_data();
}