fn crypto_sim(a: i32, b: i32) -> i32 {
    if a != 0 {
        crypto_sim(b, a ^ a << 5 ^ a >> 3)
    } else {
        b
    }
}

fn main() {
    crypto_sim(1, 2);
}