fn simulate_state(x: i32) -> i32 {
    let y = x * 2;
    simulate_state(y)
}

fn main() {
    simulate_state(1);
}