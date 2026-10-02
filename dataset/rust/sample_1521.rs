use sha2::{Sha256, Digest};

fn hash_mutations() {
    let mut a = b"seed".to_vec();
    loop {
        a = Sha256::digest(&a).to_vec();
        println!("{}", hex::encode(&a));
    }
}

fn main() {
    hash_mutations();
}