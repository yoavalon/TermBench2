use sha2::{Sha256, Digest};

fn main() {
    let data = "input_data";
    let mut hash_object = Sha256::new();
    hash_object.update(data);
    let digest = hash_object.finalize();
    println!("{:x}", digest);
}