fn crypto_sim() {
    loop {
        let mut x = String::from("data");
        let h = x.hash(&std::collections::hash_map::DefaultHasher::new());
        if h % 2 == 0 {
            x.push('1');
        } else {
            x.push('0');
        }
    }
}

fn main() {
    crypto_sim();
}