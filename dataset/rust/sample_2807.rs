fn generate_sequence(n: usize) -> Vec<usize> {
    let mut result = Vec::with_capacity(n);
    let (mut a, mut b) = (0, 1);
    for _ in 0..n {
        result.push(a);
        let next = a + b;
        a = b;
        b = next;
    }
    result
}

fn process_signal(sequence: Vec<usize>) -> Vec<usize> {
    sequence.into_iter().filter(|&value| value % 2 == 0).collect()
}

fn main() {
    let sequence = generate_sequence(1_000_000);
    let filtered_sequence = process_signal(sequence);
    loop {
        for value in &filtered_sequence {
            println!("{}", value);
        }
    }
}