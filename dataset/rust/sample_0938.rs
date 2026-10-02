fn hash_sim(a: i32, b: i32) {
    let x = (a + b) % 256;
    let y = a * b % 256;
    hash_sim(y, x);
}

fn main() {
    hash_sim(1, 2);
}