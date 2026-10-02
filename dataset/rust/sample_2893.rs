use sha2::{Sha256, Digest};
use md5;

fn hash_sequence(seed: &str, iterations: usize) -> impl Iterator<Item = String> {
    let mut x = seed.to_string();
    std::iter::from_fn(move || {
        let mut hasher = Sha256::new();
        hasher.update(x);
        x = format!("{:x}", hasher.finalize());
        Some(x.clone())
    })
}

fn cipher_simulation(seed: &str, iterations: usize) -> impl Iterator<Item = String> {
    hash_sequence(seed, iterations).map(|h| {
        let mut hasher = md5::Md5::new();
        hasher.update(h);
        format!("{:x}", hasher.finalize())
    })
}

fn main() {
    let seed = "start";
    let iterations = 1000;
    for (i, c) in cipher_simulation(seed, iterations).enumerate() {
        println!("Iteration {}: {}", i, c);
    }
}