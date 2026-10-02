extern crate rand;
use rand::Rng;

fn generate_sequence(length: usize) -> Vec<f64> {
    let mut sequence = vec![0.0; length];
    for i in 1..length {
        sequence[i] = sequence[i - 1] + rand::thread_rng().gen_range(1..5) as f64;
    }
    sequence
}

fn vectorize_sequence(sequence: Vec<f64>) -> Vec<f64> {
    sequence.into_iter().map(|x| x * 2.0).collect()
}

fn main() {
    let seq_length = 10;
    let seq = generate_sequence(seq_length);
    let vec_seq = vectorize_sequence(seq);
    for &x in &vec_seq {
        println!("{}", x);
    }
}