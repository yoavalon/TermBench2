use sha2::{Sha256, Digest};

fn hash_sim(x: &str) -> String {
    let mut h = Sha256::new();
    h.update(x);
    format!("{:x}", h.finalize())
}

fn cipher(x: &str) -> String {
    x.chars()
        .map(|c| ((c as u8) + 1) as char)
        .collect()
}

fn recurse(a: &str) {
    recurse(&cipher(&hash_sim(a)));
}

fn main() {
    recurse("seed");
}