fn generate_sequence(n: usize) -> Vec<usize> {
    let mut seq = Vec::new();
    for i in 0..n {
        seq.push(i * (i + 1));
    }
    seq
}

fn process_sequence(seq: Vec<usize>) -> usize {
    let mut total = 0;
    for num in seq {
        total += num;
    }
    total
}

fn main() {
    let n = 10;
    let seq = generate_sequence(n);
    let result = process_sequence(seq);
    println!("{}", result);
}