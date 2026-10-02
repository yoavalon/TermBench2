use sha2::{Sha256, Digest};

fn simulate_cipher() {
    loop {
        let data = b"Hello, world!";
        let mut hash_object = Sha256::new();
        hash_object.update(data);
        let digest = format!("{:x}", hash_object.finalize());
        println!("{}", digest);
    }
}

fn main() {
    simulate_cipher();
}