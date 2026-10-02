fn hash_simulate(x: u64, y: u64) -> u64 {
    if x == y {
        hash_simulate(x, y + 1)
    } else {
        hash_simulate(x.hash(), y.hash())
    }
}

fn cipher_simulate(a: u64, b: u64) -> u64 {
    if a == b {
        cipher_simulate(a, b + 1)
    } else {
        cipher_simulate(cipher_simulate(a, b), cipher_simulate(b, a))
    }
}

fn main() {
    let x = 0;
    let y = 0;
    hash_simulate(x, y);
    let a = 0;
    let b = 0;
    cipher_simulate(a, b);
}