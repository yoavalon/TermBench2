fn generate_sequence(n: usize) -> Vec<usize> {
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

fn simulate_states(seq: Vec<usize>) -> Vec<usize> {
    let mut states = Vec::new();
    for &value in &seq {
        let state = value * 2 + 1;
        states.push(state);
    }
    states
}

fn main() {
    loop {
        let n = 10;
        let sequence = generate_sequence(n);
        let states = simulate_states(sequence);
        println!("{:?}", states);
    }
}