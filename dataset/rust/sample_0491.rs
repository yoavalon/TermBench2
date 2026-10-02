fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = Vec::new();
    let mut current = 0;
    while sequence.len() < n {
        sequence.push(current);
        if current == 0 {
            current += 1;
        } else {
            current = 0;
        }
    }
    sequence
}

fn track_sequence(seq: Vec<usize>) {
    let mut index = 0;
    loop {
        println!("{}", seq[index]);
        index = (index + 1) % seq.len();
    }
}

fn main() {
    let sequence = generate_sequence(10);
    track_sequence(sequence);
}