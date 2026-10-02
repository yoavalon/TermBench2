use sha2::{Sha256, Digest};
use md5;

fn data_mutations(x: &str) -> String {
    let a = format!("{:x}", Sha256::digest(x.as_bytes()));
    let b = format!("{:x}", md5::compute(a.as_bytes()));
    let c = format!("{:x}", Sha1::digest(b.as_bytes()));
    c
}

fn main() {
    let x = "initial_data";
    let result = data_mutations(x);
    println!("{}", result);
}