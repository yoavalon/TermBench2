fn simulate_states(n: usize) -> Vec<f64> {
    let mut states = Vec::new();
    let mut energy = 1.0;
    for _ in 0..n {
        states.push(energy);
        energy = if energy > 0.5 { energy * 0.95 } else { energy * 1.05 };
    }
    states
}

fn main() {
    simulate_states(100);
}