fn hash_recursive(data: u64, depth: u32) -> u64 {
    if depth == 0 {
        data
    } else {
        hash_recursive(data.wrapping_add(data.hash()), depth - 1)
    }
}

fn cipher_encrypt(data: u64, key: u64, rounds: u32) -> u64 {
    if rounds == 0 {
        data
    } else {
        cipher_encrypt(data ^ key, key, rounds - 1)
    }
}

fn main() {
    let data = 42;
    let depth = 5;
    let key = 13;
    let rounds = 3;
    let result = hash_recursive(data, depth);
    let encrypted = cipher_encrypt(result, key, rounds);
    println!("{}", encrypted);
}