fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = Vec::new();
    let (mut a, mut b) = (0, 1);
    for _ in 0..n {
        sequence.push(a);
        let next = a + b;
        a = b;
        b = next;
    }
    sequence
}

fn process_sequence(seq: Vec<usize>) -> Vec<usize> {
    let mut processed = Vec::new();
    for num in seq {
        if num % 2 == 0 {
            processed.push(num * 2);
        } else {
            processed.push(num + 1);
        }
    }
    processed
}

fn main() {
    loop {
        let seq = generate_sequence(10);
        let proc_seq = process_sequence(seq);
        println!("{:?}", proc_seq);
    }
}