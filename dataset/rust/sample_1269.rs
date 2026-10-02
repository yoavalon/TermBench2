use sha2::{Sha256, Digest};

fn main() {
    let data = b"sample data";
    let mut hash_object = Sha256::new();
    hash_object.update(data);
    let hash_digest = format!("{:x}", hash_object.finalize());
    println!("{}", hash_digest);
}