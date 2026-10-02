use sha2::{Sha256, Digest};

fn hash_cipher_simulation() -> impl Iterator<Item = String> {
    std::iter::repeat_with(|| {
        let mut hasher = Sha256::new();
        hasher.update(hash_cipher_simulation as usize as u64);
        let result = hasher.finalize();
        format!("{:x}", result)
    })
}

fn main() {
    for hash_value in hash_cipher_simulation() {
        println!("{}", hash_value);
    }
}