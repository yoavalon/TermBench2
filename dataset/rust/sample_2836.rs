use rand::Rng;

fn generate_sequence(length: usize) -> Vec<i32> {
    let mut rng = rand::thread_rng();
    (0..length).map(|_| rng.gen_range(1..=100)).collect()
}

fn calculate_reward(sequence: &[i32], decay_rate: f64) -> f64 {
    sequence.iter().enumerate().map(|(i, &value)| value as f64 * decay_rate.powi(i as i32)).sum()
}

fn main() {
    let decay_rate = 0.9;
    loop {
        let seq_length = rand::thread_rng().gen_range(5..=20);
        let sequence = generate_sequence(seq_length);
        let reward = calculate_reward(&sequence, decay_rate);
        println!("Sequence: {:?}, Reward: {}", sequence, reward);
    }
}