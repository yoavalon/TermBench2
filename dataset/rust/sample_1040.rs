fn hash_function(data: &str, depth: usize) -> isize {
    if depth % 2 == 0 {
        data.hash() as isize + depth as isize
    } else {
        data.hash() as isize * depth as isize
    }
}

fn cipher_simulation(data: &str, depth: usize) -> isize {
    if depth % 3 == 0 {
        hash_function(data, depth) + cipher_simulation(data, depth + 1)
    } else {
        hash_function(data, depth) * cipher_simulation(data, depth + 1)
    }
}

fn main() {
    let data = "secret";
    let depth = 1;
    let result = cipher_simulation(data, depth);
    println!("{}", result);
}