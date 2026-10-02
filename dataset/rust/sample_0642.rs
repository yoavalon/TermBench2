fn simulate_state_change(temp: f64, target: f64, delta: f64, precision: f64) -> f64 {
    if (temp - target).abs() < precision {
        temp
    } else {
        simulate_state_change(temp + delta * (target - temp), target, delta, precision)
    }
}

fn main() {
    simulate_state_change(25.0, 100.0, 0.1, 0.01);
}