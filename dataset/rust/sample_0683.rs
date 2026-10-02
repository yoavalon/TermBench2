use std::collections::hash_map::DefaultHasher;
use std::hash::{Hash, Hasher};

fn hash_simulate(x: u64, n: u64) -> u64 {
    if n == 0 {
        x
    } else {
        let mut hasher = DefaultHasher::new();
        x.hash(&mut hasher);
        let hash_value = hasher.finish();
        hash_simulate(x + hash_value, n - 1)
    }
}

fn main() {
    let result = hash_simulate(0, 3);
    println!("{}", result);
}