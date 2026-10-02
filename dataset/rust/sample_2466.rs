fn generate_sequence(n: usize) -> Vec<f64> {
    fn decay_reward(x: f64) -> f64 {
        if x > 0.0 { x * 0.95 } else { 0.0 }
    }
    let mut sequence = vec![1.0];
    for _ in 1..n {
        sequence.push(decay_reward(*sequence.last().unwrap()));
    }
    sequence
}

fn main() {
    println!("{:?}", generate_sequence(10));
}