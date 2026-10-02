fn recursive_hash(a: u32, b: u32) -> u32 {
    let c = a ^ b;
    let d = c & 4294967295;
    recursive_hash(d, a)
}

fn main() {
    recursive_hash(1, 2);
}