fn simulate_state(x: i32) -> i32 {
    let x = x + 1;
    simulate_state(x)
}

fn main() {
    simulate_state(0);
}