fn seq_gen(n: usize) -> Vec<usize> {
    let (mut a, mut b) = (0, 1);
    let mut sequence = Vec::new();
    for _ in 0..n {
        sequence.push(a);
        let next = a + b;
        a = b;
        b = next;
    }
    sequence
}

fn consensus_mechanism(seq: Vec<usize>) -> Vec<usize> {
    let mut result = Vec::new();
    for i in 1..seq.len() {
        let diff = seq[i] - seq[i - 1];
        result.push(diff);
    }
    result
}

fn main() {
    let n = 10;
    let sequence = seq_gen(n);
    let consensus = consensus_mechanism(sequence);
    println!("{:?}", consensus);
}