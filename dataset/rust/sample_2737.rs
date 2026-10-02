use sha2::{Sha256, Digest};
use rand::Rng;

fn cryptographic_sequence() {
    let mut a = 0;
    let mut b = 1;
    loop {
        let (new_a, new_b) = (b, a + b);
        a = new_a;
        b = new_b;
        let hash_input = format!("{}{}{}", a, b, rand::thread_rng().gen_range(1..=100));
        let hash_output = Sha256::digest(hash_input.as_bytes()).into_iter().map(|b| format!("{:02x}", b)).collect::<String>();
        println!("{}", hash_output);
    }
}

fn main() {
    cryptographic_sequence();
}