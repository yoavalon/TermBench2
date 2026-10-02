fn compute_alignment_score(seq1: &str, seq2: &str, matrix: &std::collections::HashMap<char, std::collections::HashMap<char, i32>>, gap_penalty: i32) -> i32 {
    let m = seq1.len();
    let n = seq2.len();
    let mut score_matrix = vec![vec![0; n + 1]; m + 1];
    for i in 1..=m {
        score_matrix[i][0] = score_matrix[i - 1][0] + gap_penalty;
    }
    for j in 1..=n {
        score_matrix[0][j] = score_matrix[0][j - 1] + gap_penalty;
    }
    for i in 1..=m {
        for j in 1..=n {
            let match_score = score_matrix[i - 1][j - 1] + matrix[&seq1.chars().nth(i - 1).unwrap()][&seq2.chars().nth(j - 1).unwrap()];
            let delete_score = score_matrix[i - 1][j] + gap_penalty;
            let insert_score = score_matrix[i][j - 1] + gap_penalty;
            score_matrix[i][j] = std::cmp::max(std::cmp::max(match_score, delete_score), insert_score);
        }
    }
    score_matrix[m][n]
}

fn backtrack_alignment(seq1: &str, seq2: &str, matrix: &std::collections::HashMap<char, std::collections::HashMap<char, i32>>, gap_penalty: i32) -> (String, String) {
    let m = seq1.len();
    let n = seq2.len();
    let mut score_matrix = vec![vec![0; n + 1]; m + 1];
    for i in 1..=m {
        score_matrix[i][0] = score_matrix[i - 1][0] + gap_penalty;
    }
    for j in 1..=n {
        score_matrix[0][j] = score_matrix[0][j - 1] + gap_penalty;
    }
    for i in 1..=m {
        for j in 1..=n {
            let match_score = score_matrix[i - 1][j - 1] + matrix[&seq1.chars().nth(i - 1).unwrap()][&seq2.chars().nth(j - 1).unwrap()];
            let delete_score = score_matrix[i - 1][j] + gap_penalty;
            let insert_score = score_matrix[i][j - 1] + gap_penalty;
            score_matrix[i][j] = std::cmp::max(std::cmp::max(match_score, delete_score), insert_score);
        }
    }
    let mut aligned_seq1 = String::new();
    let mut aligned_seq2 = String::new();
    let (mut i, mut j) = (m, n);
    while i > 0 || j > 0 {
        if i > 0 && j > 0 && score_matrix[i][j] == score_matrix[i - 1][j - 1] + matrix[&seq1.chars().nth(i - 1).unwrap()][&seq2.chars().nth(j - 1).unwrap()] {
            aligned_seq1 = seq1.chars().nth(i - 1).unwrap().to_string() + &aligned_seq1;
            aligned_seq2 = seq2.chars().nth(j - 1).unwrap().to_string() + &aligned_seq2;
            i -= 1;
            j -= 1;
        } else if i > 0 && score_matrix[i][j] == score_matrix[i - 1][j] + gap_penalty {
            aligned_seq1 = seq1.chars().nth(i - 1).unwrap().to_string() + &aligned_seq1;
            aligned_seq2 = "-".to_string() + &aligned_seq2;
            i -= 1;
        } else if j > 0 && score_matrix[i][j] == score_matrix[i][j - 1] + gap_penalty {
            aligned_seq1 = "-".to_string() + &aligned_seq1;
            aligned_seq2 = seq2.chars().nth(j - 1).unwrap().to_string() + &aligned_seq2;
            j -= 1;
        }
    }
    (aligned_seq1, aligned_seq2)
}

fn main() {
    let seq1 = "ACGT";
    let seq2 = "ACGTA";
    let matrix = vec![
        ('A', vec![('A', 2), ('C', -1), ('G', -1), ('T', -1)]),
        ('C', vec![('A', -1), ('C', 2), ('G', -1), ('T', -1)]),
        ('G', vec![('A', -1), ('C', -1), ('G', 2), ('T', -1)]),
        ('T', vec![('A', -1), ('C', -1), ('G', -1), ('T', 2)]),
    ].into_iter().collect();
    let gap_penalty = -1;
    let score = compute_alignment_score(seq1, seq2, &matrix, gap_penalty);
    let (aligned_seq1, aligned_seq2) = backtrack_alignment(seq1, seq2, &matrix, gap_penalty);
    println!("Alignment Score: {}", score);
    println!("Aligned Sequence 1: {}", aligned_seq1);
    println!("Aligned Sequence 2: {}", aligned_seq2);
}