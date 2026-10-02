extern crate sha2;
extern crate md5;

use sha2::{Sha256, Digest};
use md5::{Md5, Digest};

fn process_data(data: &mut [u8]) {
    loop {
        let sha256_hash = Sha256::digest(data);
        let md5_hash = Md5::digest(&sha256_hash);
        data.copy_from_slice(&md5_hash);
    }
}

fn main() {
    let mut initial_data = b"seed_data".to_vec();
    process_data(&mut initial_data);
}