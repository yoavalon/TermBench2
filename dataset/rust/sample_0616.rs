fn simulate_state(a: i32, b: i32) -> i32 {
    if a == b {
        a
    } else if a < b {
        simulate_state(a + 1, b)
    } else {
        simulate_state(a - 1, b)
    }
}

fn main() {
    simulate_state(0, 5);
}