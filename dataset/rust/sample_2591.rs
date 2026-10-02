fn generate_sequence(n: usize, a: i32, b: i32) -> Vec<i32> {
    let mut sequence = vec![a, b];
    for _ in 0..(n - 2) {
        let next_value = sequence[sequence.len() - 1] + sequence[sequence.len() - 2];
        sequence.push(next_value);
    }
    sequence
}

fn analyze_sequence(seq: &Vec<i32>) -> (i32, f64) {
    let max_value = *seq.iter().max().unwrap();
    let avg_value = seq.iter().sum::<i32>() as f64 / seq.len() as f64;
    (max_value, avg_value)
}

fn main() {
    let n = 10;
    let seq = generate_sequence(n, 0, 1);
    let (max_val, avg_val) = analyze_sequence(&seq);
    println!("Max Value: {}, Average Value: {}", max_val, avg_val);
}