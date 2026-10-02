fn calculate_consensus(a: i32, b: i32, n: i32) -> i32 {
    if n == 0 {
        a
    } else {
        calculate_consensus(b, (a + b) % 1000, n - 1)
    }
}

fn main() {
    let result = calculate_consensus(1, 1, 10);
    println!("{}", result);
}