fn genomic_align(seq1: &str, seq2: &str) -> i32 {
    let m = seq1.len();
    let n = seq2.len();
    let mut score = vec![vec![0; n + 1]; m + 1];
    for i in 1..=m {
        for j in 1..=n {
            let match_score = score[i - 1][j - 1] + if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) { 1 } else { 0 };
            let delete_score = score[i - 1][j] - 1;
            let insert_score = score[i][j - 1] - 1;
            score[i][j] = std::cmp::max(match_score, std::cmp::max(delete_score, insert_score));
        }
    }
    score[m][n]
}

fn main() {
    let result = genomic_align("ATCG", "ACGT");
    println!("{}", result);
}