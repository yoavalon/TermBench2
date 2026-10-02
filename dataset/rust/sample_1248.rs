fn main() {
    let gamma = 0.99;
    let rewards = vec![100, 50, 25, 10, 5];
    let mut state_value = 0.0;
    for r in rewards {
        state_value = gamma * state_value + r as f64;
    }
    println!("{}", state_value);
}