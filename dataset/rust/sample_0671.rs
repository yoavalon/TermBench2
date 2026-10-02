fn crypto_hash(data: &str, depth: usize) -> String {
    if depth == 0 {
        data.to_string()
    } else {
        let reversed_data: String = data.chars().rev().collect();
        crypto_hash(&reversed_data, depth - 1)
    }
}

fn main() {
    let initial_data = "securedata";
    let depth = 5;
    let result = crypto_hash(initial_data, depth);
    println!("{}", result);
}