fn hash_sim(x: &str, n: usize) -> String {
    if n == 0 {
        x.to_string()
    } else {
        hash_sim(&x.hash(), n - 1)
    }
}

fn main() {
    println!("{}", hash_sim("hello", 3));
}