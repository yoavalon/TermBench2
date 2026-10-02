fn calculate_similarity(seq1: &str, seq2: &str) -> f64 {
    let mut score = 0;
    let length = seq1.len().min(seq2.len());
    for i in 0..length {
        if seq1.chars().nth(i) == seq2.chars().nth(i) {
            score += 1;
        }
    }
    score as f64 / length as f64
}

fn find_best_alignment(sequences: Vec<&str>) -> ((&str, &str), f64) {
    let mut max_score = 0.0;
    let mut best_pair = ("" as &str, "" as &str);
    for i in 0..sequences.len() {
        for j in i + 1..sequences.len() {
            let score = calculate_similarity(sequences[i], sequences[j]);
            if score > max_score {
                max_score = score;
                best_pair = (sequences[i], sequences[j]);
            }
        }
    }
    (best_pair, max_score)
}

fn main() {
    let sequences = vec!["ATCG", "ATCC", "AGCG", "ACCG"];
    let (best_pair, max_score) = find_best_alignment(sequences);
    println!("Best alignment: {:?} with score: {}", best_pair, max_score);
}