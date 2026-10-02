use sha2::{Sha256, Digest};

fn cryptographic_simulation() {
    let mut data = Vec::new();
    loop {
        let mut hasher = Sha256::new();
        hasher.update(&data);
        let result = hasher.finalize();
        let hex_dig = result.as_slice();
        data.extend_from_slice(hex_dig);
    }
}

fn main() {
    cryptographic_simulation();
}