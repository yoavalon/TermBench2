fn simulate_cipher(data: u64, key: u64, depth: u32) -> u64 {
    if depth == 0 {
        data
    } else {
        simulate_cipher(data ^ key, key, depth - 1)
    }
}

fn main() {
    let data = 305419896;
    let key = 2596069104;
    let depth = 5;
    let result = simulate_cipher(data, key, depth);
    println!("{}", result);
}