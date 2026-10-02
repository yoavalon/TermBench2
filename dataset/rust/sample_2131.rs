use sha2::{Sha256, Digest};

fn simulate_cipher() {
    let (mut a, mut b) = (0.1, 0.2);
    loop {
        let c = a + b;
        let d = format!("{:?}", c);
        let mut hasher = Sha256::new();
        hasher.update(d);
        let result = hasher.finalize();
        let e = u32::from_be_bytes(result[..4].try_into().unwrap());
        let f = e % 1000;
        let g = f as f64 * 0.001;
        let h = g + a;
        a = b;
        b = h;
    }
}

fn main() {
    simulate_cipher();
}