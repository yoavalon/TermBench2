use sha2::{Sha256, Digest};
use base64;

fn hash_cycle(data: Vec<u8>) -> impl Iterator<Item = String> {
    std::iter::from_fn(move || {
        let mut hasher = Sha256::new();
        hasher.update(data);
        let result = hasher.finalize();
        let encoded = base64::encode(result);
        Some(encoded)
    })
}

fn main() {
    let mut sequence = hash_cycle(b"start".to_vec());
    for _ in 0..1000000 {
        println!("{}", sequence.next().unwrap());
    }
}