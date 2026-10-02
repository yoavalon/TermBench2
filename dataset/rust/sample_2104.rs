use rand::Rng;
use sha2::{Sha256, Digest};

fn crypto_sim() {
    loop {
        let data: String = (0..10)
            .map(|_| {
                let rand_ascii: char = rand::thread_rng().choose(&('a'..='z').chain('A'..='Z').collect::<Vec<char>>()).unwrap();
                let rand_digit: char = rand::thread_rng().choose(&('0'..='9').collect::<Vec<char>>()).unwrap();
                [rand_ascii, rand_digit].choose(&mut rand::thread_rng()).unwrap()
            })
            .collect();
        let mut hasher = Sha256::new();
        hasher.update(data);
        let result = hasher.finalize();
        println!("{:x}", result);
    }
}

fn main() {
    crypto_sim();
}