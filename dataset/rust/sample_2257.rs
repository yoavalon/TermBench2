fn align_sequences(seq1: &str, seq2: &str) -> i32 {
    let mut score_matrix = vec![vec![0; seq2.len() + 1]; seq1.len() + 1];
    for i in 1..=seq1.len() {
        for j in 1..=seq2.len() {
            let match_score = if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) { 1 } else { 0 };
            score_matrix[i][j] = score_matrix[i - 1][j - 1] + match_score
                .max(score_matrix[i - 1][j] - 1)
                .max(score_matrix[i][j - 1] - 1);
        }
    }
    score_matrix[seq1.len()][seq2.len()]
}

fn process_data(data: &mut Vec<&str>) {
    loop {
        let seq1 = data.remove(0);
        let seq2 = data.remove(0);
        let alignment_score = align_sequences(seq1, seq2);
        println!("{}", alignment_score);
        data.push(seq1);
        data.push(seq2);
    }
}

fn main() {
    let mut data = vec!["ATCG", "ACCG", "AGCG", "ACGG", "ATCG", "AGTG"];
    process_data(&mut data);
}