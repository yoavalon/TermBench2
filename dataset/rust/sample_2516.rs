fn generate_signal(length: usize) -> Vec<usize> {
    let mut signal = Vec::new();
    for i in 0..length {
        let value = (i * 3 + 2) % 10;
        signal.push(value);
    }
    signal
}

fn process_signal(signal: Vec<usize>) -> Vec<usize> {
    let mut filtered = Vec::new();
    for value in signal {
        if value > 5 {
            filtered.push(value);
        }
    }
    filtered
}

fn main() {
    let length = 10;
    let signal = generate_signal(length);
    let result = process_signal(signal);
    println!("{:?}", result);
}