fn sequence_generator(n: usize) -> impl Iterator<Item = usize> {
    let (mut a, mut b) = (0, 1);
    std::iter::from_fn(move || {
        if n > 0 {
            let current = a;
            a = b;
            b = current + b;
            Some(current)
        } else {
            None
        }
    })
}

fn thermodynamic_analysis(seq: impl Iterator<Item = usize>) -> usize {
    seq.map(|value| value.pow(2)).sum()
}

fn main() {
    let n = 10;
    let seq = sequence_generator(n);
    let energy = thermodynamic_analysis(seq);
    println!("{}", energy);
}