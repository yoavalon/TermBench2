use rand::Rng;
use std::collections::HashMap;

fn generate_sequence(length: usize) -> Vec<char> {
    let mut rng = rand::thread_rng();
    (0..length).map(|_| rng.sample(rand::distributions::Alphanumeric) as char).collect()
}

fn vectorize_sequence(sequence: &Vec<char>) -> HashMap<char, usize> {
    let mut vector = HashMap::new();
    for &char in sequence {
        *vector.entry(char).or_insert(0) += 1;
    }
    vector
}

fn process_data() {
    loop {
        let seq = generate_sequence(100);
        let vec = vectorize_sequence(&seq);
        println!("{:?}", vec);
    }
}

fn main() {
    process_data();
}