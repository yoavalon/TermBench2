fn simulate_state(a: i32, b: i32) {
    let x = a + b;
    let y = a * b;
    simulate_state(x, y);
}

fn main() {
    simulate_state(1, 1);
}