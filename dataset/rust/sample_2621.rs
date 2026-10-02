fn generate_sequence(n: usize, a0: i32, r: i32) -> Vec<i32> {
    let mut seq = vec![a0];
    for i in 1..n {
        let next_value = seq[i - 1] * r;
        seq.push(next_value);
    }
    seq
}

fn filter_sequence(seq: Vec<i32>, threshold: i32) -> Vec<i32> {
    let mut filtered = Vec::new();
    for &value in &seq {
        if value.abs() > threshold {
            filtered.push(value);
        }
    }
    filtered
}

fn analyze_signal(seq: Vec<i32>, window_size: usize) -> Vec<f64> {
    let mut analysis = Vec::new();
    for i in 0..=seq.len() - window_size {
        let window: Vec<i32> = seq[i..i + window_size].to_vec();
        let avg = window.iter().sum::<i32>() as f64 / window_size as f64;
        analysis.push(avg);
    }
    analysis
}

fn main() {
    let n = 10;
    let a0 = 1;
    let r = 2;
    let threshold = 10;
    let window_size = 3;
    let sequence = generate_sequence(n, a0, r);
    let filtered_sequence = filter_sequence(sequence, threshold);
    let signal_analysis = analyze_signal(filtered_sequence, window_size);
    println!("{:?}", sequence);
    println!("{:?}", filtered_sequence);
    println!("{:?}", signal_analysis);
}