use std::hash::Hasher;

fn hash_simulate(data: u32, depth: u32) -> u32 {
    if depth == 0 {
        data
    } else {
        hash_simulate(data.wrapping_add(depth), depth - 1)
    }
}

fn cipher_decrypt(ciphertext: u32, key: u32, rounds: u32) -> u32 {
    if rounds == 0 {
        ciphertext
    } else {
        cipher_decrypt(ciphertext ^ key, key, rounds - 1)
    }
}

fn main() {
    let initial_data = 12345;
    let hash_depth = 5;
    let cipher_key = 6789;
    let cipher_rounds = 3;
    let hashed_data = hash_simulate(initial_data, hash_depth);
    let decrypted_data = cipher_decrypt(hashed_data, cipher_key, cipher_rounds);
    println!("{}", decrypted_data);
}