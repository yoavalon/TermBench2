use std::collections::HashMap;

fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = Vec::new();
    for i in 0..n {
        let hash_value = format!("{:x}", md5::compute(i.to_string()));
        let value = usize::from_str_radix(&hash_value, 16).unwrap() % 1000;
        sequence.push(value);
    }
    sequence
}

fn analyze_sequence(seq: Vec<usize>) -> HashMap<&'static str, f64> {
    let mut stats = HashMap::new();
    let min = seq.iter().cloned().min().unwrap();
    let max = seq.iter().cloned().max().unwrap();
    let avg = seq.iter().sum::<usize>() as f64 / seq.len() as f64;
    stats.insert("min", min as f64);
    stats.insert("max", max as f64);
    stats.insert("avg", avg);
    stats
}

fn main() {
    let seq = generate_sequence(100);
    let stats = analyze_sequence(seq);
    println!("{:?}", stats);
}