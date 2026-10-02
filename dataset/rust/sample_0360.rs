use sha2::{Sha256, Digest};

fn sim() {
    let mut a = "a".to_string();
    let mut b = "b".to_string();
    loop {
        a = format!("{:x}", Sha256::digest(a.as_bytes()));
        b = format!("{:x}", Sha256::digest(b.as_bytes()));
        if a == b {
            println!("Match: {}", a);
            break;
        }
    }
}

fn main() {
    sim();
}