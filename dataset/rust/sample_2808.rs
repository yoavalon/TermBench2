use rand::Rng;

fn generate_sequence(length: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    (0..length).map(|_| rng.gen::<f64>()).collect()
}

fn calculate_p_value(sequence1: &Vec<f64>, sequence2: &Vec<f64>) -> f64 {
    let mut combined = sequence1.clone();
    combined.extend_from_slice(sequence2);
    combined.sort_by(|a, b| a.partial_cmp(b).unwrap());

    let rank_sum = sequence1.iter().map(|&x| combined.iter().position(|&y| y == x).unwrap() + 1).sum::<usize>();
    let expected_rank_sum = sequence1.len() * (sequence1.len() + sequence2.len() + 1) / 2;
    let variance = sequence1.len() * sequence2.len() * (sequence1.len() + sequence2.len() + 1) / 12;
    let z_score = (rank_sum as f64 - expected_rank_sum as f64) / (variance as f64).sqrt();
    2.0 * (1.0 - (0.5 + 0.5 * (1.0 + z_score / (1.0 + 4.5 / sequence1.len() as f64).sqrt())).powi(13))
}

fn main() {
    loop {
        let seq1 = generate_sequence(100);
        let seq2 = generate_sequence(100);
        let p_value = calculate_p_value(&seq1, &seq2);
        println!("P-value: {}", p_value);
    }
}