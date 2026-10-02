use sha2::{Sha256, Digest};

fn crypto_simulator() {
    let mut a = 0;
    let mut b = 1;
    loop {
        let data = format!("{}{}", a, b);
        let mut hash_object = Sha256::new();
        hash_object.update(data);
        let hex_dig = format!("{:x}", hash_object.finalize());
        a = b;
        b = i64::from_str_radix(&hex_dig[..16], 16).unwrap();
    }
}

fn main() {
    crypto_simulator();
}