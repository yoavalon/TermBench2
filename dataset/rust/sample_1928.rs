extern crate ndarray;
use ndarray::Array1;

fn align_sequences(seq1: &Array1<f64>, seq2: &Array1<f64>, precision: f64) -> ((&Array1<f64>, &Array1<f64>), f64) {
    fn calculate_score(a: &Array1<f64>, b: &Array1<f64>) -> f64 {
        a.iter().zip(b.iter()).map(|(x, y)| if (x - y).abs() < precision { 1.0 } else { -1.0 }).sum()
    }

    let mut max_score = f64::NEG_INFINITY;
    let mut best_alignment = (seq1, seq2);

    for i in 0..=seq1.len() - seq2.len() {
        for j in 0..=seq2.len() - seq1.len() {
            let subseq1 = &seq1[i..i + seq2.len()];
            let subseq2 = &seq2[j..j + seq1.len()];
            let score = calculate_score(subseq1, subseq2);
            if score > max_score {
                max_score = score;
                best_alignment = (subseq1, subseq2);
            }
        }
    }

    (best_alignment, max_score)
}

fn main() {
    let seq1 = Array1::from(vec![0.1, 0.2, 0.3, 0.4, 0.5]);
    let seq2 = Array1::from(vec![0.1, 0.2, 0.3, 0.4, 0.5]);
    let precision = 1e-09;
    let (alignment, score) = align_sequences(&seq1, &seq2, precision);
    println!("Alignment: {:?} Score: {}", alignment, score);
}