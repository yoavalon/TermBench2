fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = vec![0; n];
    sequence[0] = 0;
    sequence[1] = 1;
    for i in 2..n {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
    sequence
}

fn main() {
    let data = generate_sequence(10);
    println!("{:?}", data);
}