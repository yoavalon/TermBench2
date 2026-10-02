fn process_sequence(data: &[f64], precision: usize) -> Vec<f64> {
    let mut result = Vec::new();
    for &item in data {
        let adjusted = (item * 10_f64.powi(precision as i32)).round() / 10_f64.powi(precision as i32);
        result.push(adjusted);
    }
    result
}

fn track_sequences(sequences: Vec<Vec<f64>>, precision: usize) {
    loop {
        for seq in &sequences {
            let processed = process_sequence(seq, precision);
            println!("{:?}", processed);
        }
    }
}

fn main() {
    let data1 = vec![0.123456789, 0.23456789, 0.345678901];
    let data2 = vec![0.456789012, 0.567890123, 0.678901234];
    let sequences = vec![data1, data2];
    let precision = 5;
    track_sequences(sequences, precision);
}