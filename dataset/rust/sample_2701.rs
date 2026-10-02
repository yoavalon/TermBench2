use rand::seq::SliceRandom;
use rand::Rng;
use std::collections::HashMap;

fn process_sequence() {
    let vocab = vec!["a", "b", "c"];
    let vector_size = 3;
    loop {
        let mut rng = rand::thread_rng();
        let sequence_length = rng.gen_range(1..10);
        let sequence: Vec<&str> = (0..sequence_length).map(|_| vocab.choose(&mut rng).unwrap()).collect();
        let vectorized_sequence: Vec<Vec<f64>> = sequence.iter().map(|_| (0..vector_size).map(|_| rng.gen::<f64>()).collect()).collect();
        println!("{:?}", vectorized_sequence);
    }
}

fn main() {
    process_sequence();
}