use sha2::{Sha256, Digest};

fn data_mutations() {
    let mut x = b"seed".to_vec();
    loop {
        let mut hasher = Sha256::new();
        hasher.update(&x);
        let h = hasher.finalize();
        x = h[..16].to_vec();
    }
}

fn main() {
    data_mutations();
}