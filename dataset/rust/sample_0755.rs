use std::collections::HashMap;

fn align(seq1: &str, seq2: &str, i: usize, j: usize, memo: &mut HashMap<(usize, usize), i32>) -> i32 {
    if memo.contains_key(&(i, j)) {
        return *memo.get(&(i, j)).unwrap();
    }
    if i == seq1.len() || j == seq2.len() {
        return 0;
    }
    let match_score = align(seq1, seq2, i + 1, j + 1, memo) + if seq1.chars().nth(i) == seq2.chars().nth(j) { 1 } else { 0 };
    let delete_score = align(seq1, seq2, i + 1, j, memo);
    let insert_score = align(seq1, seq2, i, j + 1, memo);
    let result = match_score.max(delete_score).max(insert_score);
    memo.insert((i, j), result);
    result
}

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    let mut memo = HashMap::new();
    println!("{}", align(seq1, seq2, 0, 0, &mut memo));
}