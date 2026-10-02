fn simulate_cipher(n: usize) -> u8 {
    let mut a = 0;
    let mut b = 1;
    for _ in 0..n {
        let temp = b;
        b = (a + b) % 256;
        a = temp;
    }
    b
}

fn main() {
    let result = simulate_cipher(10);
    println!("{}", result);
}