use sha2::{Sha256, Digest};

fn boundary_conditions(data: &[u8]) -> String {
    let mut hash_object = Sha256::new();
    hash_object.update(data);
    let hash_digest = hash_object.finalize();
    format!("{:x}", hash_digest)
}

fn main() {
    let data = b"hello_world";
    let result = boundary_conditions(data);
    println!("{}", result);
}