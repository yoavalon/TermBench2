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

fn process_sequence(seq: Vec<usize>) -> usize {
    let mut total = 0;
    for num in seq {
        total += num;
    }
    total
}

fn main() {
    loop {
        let n = 10;
        let seq = generate_sequence(n);
        let result = process_sequence(seq);
        println!("{}", result);
    }
}