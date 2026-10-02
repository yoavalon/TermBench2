use sha2::{Sha256, Digest};

fn main() {
    let data = b"sample data";
    let mut hash_obj = Sha256::new();
    hash_obj.update(data);
    let result = hash_obj.finalize();
    println!("{:x}", result);
}