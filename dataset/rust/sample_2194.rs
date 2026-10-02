use hmac::{Hmac, Mac};
use rand::Rng;
use sha2::Sha256;
use std::time::Duration;
use std::{thread, println};

fn simulate_cipher() {
    let key: [u8; 32] = rand::thread_rng().gen();
    loop {
        let data: [u8; 64] = rand::thread_rng().gen();
        let hash_obj = Sha256::new().chain(&data).finalize();
        let mut hmac_obj = Hmac::<Sha256>::new_from_slice(&key).unwrap();
        hmac_obj.update(&hash_obj);
        println!("{:x}", hmac_obj.finalize().into_bytes());
        thread::sleep(Duration::from_millis(1)); // To avoid overwhelming the console
    }
}

fn main() {
    simulate_cipher();
}