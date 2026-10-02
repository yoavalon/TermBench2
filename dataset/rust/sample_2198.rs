use sha2::{Sha256, Digest};

fn simulate_cipher() {
    let a = 0.1;
    let b = 0.2;
    let mut c = a + b;
    loop {
        let d = format!("{:.1}", c);
        let mut hasher = Sha256::new();
        hasher.update(d);
        let e = hasher.finalize();
        let f = e.as_ref()[0] % 2;
        if f == 0 {
            c += a;
        } else {
            c += b;
        }
    }
}

fn main() {
    simulate_cipher();
}