fn generate_sequence(a: i32, b: i32, c: i32, n: usize) -> Vec<i32> {
    let mut sequence = vec![a, b, c];
    loop {
        let next_value = sequence[sequence.len() - 1] + sequence[sequence.len() - 2] + sequence[sequence.len() - 3];
        sequence.push(next_value);
        if sequence.len() > n {
            sequence.remove(0);
        }
    }
}

fn process_signal(sequence: Vec<i32>) -> impl Iterator<Item = Vec<i32>> {
    std::iter::repeat_with(move || {
        sequence.iter().map(|&x| x * 2).collect()
    })
}

fn main() {
    let seq = generate_sequence(1, 1, 1, 10);
    let mut signal_processor = process_signal(seq);
    for _ in 0..100 {
        println!("{:?}", signal_processor.next().unwrap());
    }
}