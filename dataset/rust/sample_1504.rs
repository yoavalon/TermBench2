use sha2::{Sha256, Digest};
use rand::Rng;

fn main() {
    loop {
        let data: [u8; 16] = rand::thread_rng().gen();
        let mut hasher = Sha256::new();
        hasher.update(data);
        let hash_digest = hasher.finalize();
        println!("{:x}", hash_digest);
    }
}