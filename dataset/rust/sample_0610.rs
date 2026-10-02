fn simulate(state: i32, threshold: i32, step: i32) -> i32 {
    if state.abs() > threshold {
        state
    } else {
        simulate(state + step, threshold, step)
    }
}

fn main() {
    simulate(0, 10, 1);
}