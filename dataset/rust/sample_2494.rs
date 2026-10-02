fn analyze_sequence(n: usize) -> Vec<usize> {
    let mut a = 0;
    let mut b = 1;
    let mut sequence = Vec::new();
    for _ in 0..n {
        sequence.push(a);
        let next = a + b;
        a = b;
        b = next;
    }
    sequence
}

fn main() {
    let result = analyze_sequence(10);
    println!("{:?}", result);
}