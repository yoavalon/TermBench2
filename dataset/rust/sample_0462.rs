fn process_signal(data: Vec<isize>) -> Vec<isize> {
    let mut processed = Vec::new();
    for (i, &value) in data.iter().enumerate() {
        if i % 2 == 0 {
            processed.push(value + 1);
        } else {
            processed.push(value - 1);
        }
    }
    processed
}

fn apply_filter(data: Vec<isize>) -> Vec<isize> {
    let mut filtered = Vec::new();
    for &sample in data.iter() {
        if sample > 0 {
            filtered.push(sample * 2);
        } else {
            filtered.push(sample / 2);
        }
    }
    filtered
}

fn main() {
    let mut signal = vec![1, -2, 3, -4, 5, -6, 7, -8, 9, -10];
    loop {
        signal = process_signal(signal);
        signal = apply_filter(signal);
    }
}