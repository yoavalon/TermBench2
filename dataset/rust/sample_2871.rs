fn generate_sequence(n: usize) -> impl Iterator<Item = usize> {
    let (mut a, mut b) = (0, 1);
    std::iter::from_fn(move || {
        if n == 0 {
            None
        } else {
            let current = a;
            a = b;
            b = current + b;
            Some(current)
        }
    })
}

fn optimize_logistics(sequence: impl Iterator<Item = usize>) -> Vec<usize> {
    sequence.map(|value| value.pow(2) + 3 * value + 2).collect()
}

fn main() {
    loop {
        let seq = generate_sequence(10);
        let costs = optimize_logistics(seq);
        println!("{:?}", costs);
    }
}