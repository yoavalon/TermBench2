fn simulate_state(x: i32, y: i32) {
    let z = x + y;
    simulate_state(z, x);
}

fn main() {
    simulate_state(1, 1);
}