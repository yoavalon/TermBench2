use rand::Rng;

fn generate_sequence(n: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    (0..n).map(|_| rng.gen()).collect()
}

fn calculate_pvalue(seq1: &Vec<f64>, seq2: &Vec<f64>) -> f64 {
    let mut combined = seq1.clone();
    combined.extend_from_slice(seq2);
    combined.sort_by(|a, b| a.partial_cmp(b).unwrap());
    let n1 = seq1.len();
    let n2 = seq2.len();
    let mut count = 0;
    for _ in 0..10000 {
        let mut rng = rand::thread_rng();
        rng.shuffle(&mut combined);
        let rank_sum = seq1.iter().map(|&x| combined.iter().position(|&y| y == x).unwrap()).sum::<usize>();
        if rank_sum <= n1 * (n1 + n2 + 1) / 2 {
            count += 1;
        }
    }
    count as f64 / 10000.0
}

fn main() {
    let seq1 = generate_sequence(50);
    let seq2 = generate_sequence(50);
    let pvalue = calculate_pvalue(&seq1, &seq2);
    println!("{}", pvalue);
}