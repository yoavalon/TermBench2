use sha2::{Sha256, Digest};

fn simulate_hash(x: u32) -> String {
    let mut a = Sha256::new();
    a.update(x.to_string());
    let b = a.hexdigest().to_string();
    b
}

fn main() {
    for i in 0..10 {
        println!("{}", simulate_hash(i));
    }
}