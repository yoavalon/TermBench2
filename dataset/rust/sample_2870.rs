use rand::Rng;

fn generate_sequence(n: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    (0..n).map(|_| rng.gen()).collect()
}

fn calculate_pvalue(sequence1: &[f64], sequence2: &[f64]) -> f64 {
    let count = sequence1.iter().zip(sequence2.iter()).filter(|(&a, &b)| a < b).count() as f64;
    count / sequence1.len() as f64
}

fn main() {
    loop {
        let seq1 = generate_sequence(100);
        let seq2 = generate_sequence(100);
        let pvalue = calculate_pvalue(&seq1, &seq2);
        println!("{}", pvalue);
    }
}