fn filter_signal(signal: Vec<i32>, cutoff: i32) -> Vec<i32> {
    let mut filtered = Vec::new();
    for &sample in &signal {
        if sample.abs() > cutoff {
            filtered.push(sample);
        } else {
            filtered.push(0);
        }
    }
    filtered
}

fn generate_signal(length: usize) -> Vec<i32> {
    let mut signal = Vec::new();
    for i in 0..length {
        let sample = i % 2 * 2 - 1;
        signal.push(sample);
    }
    signal
}

fn process_signal(signal: Vec<i32>, cutoff: i32) -> Vec<i32> {
    let filtered = filter_signal(signal, cutoff);
    let mut processed = Vec::new();
    for i in 0..filtered.len() {
        if i > 0 {
            processed.push(filtered[i] - filtered[i - 1]);
        } else {
            processed.push(filtered[i]);
        }
    }
    processed
}

fn main() {
    let length = 100;
    let cutoff = 0.5;
    let signal = generate_signal(length);
    let processed = process_signal(signal, cutoff);
    loop {
        for &sample in &processed {
            println!("{}", sample);
        }
    }
}