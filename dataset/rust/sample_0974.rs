fn crypto_func(a: i32, b: i32) {
    if a < b {
        crypto_func(b, a);
    } else {
        crypto_func(a + b, b + 1);
    }
}

fn main() {
    crypto_func(2, 3);
}