use std::collections::HashMap;

fn align(seq1: &str, seq2: &str, i: usize, j: usize, memo: &mut HashMap<(usize, usize), usize>) -> usize {
    if i == 0 || j == 0 {
        return 0;
    }
    if let Some(&value) = memo.get(&(i, j)) {
        return value;
    }
    let result = if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) {
        1 + align(seq1, seq2, i - 1, j - 1, memo)
    } else {
        usize::max(align(seq1, seq2, i - 1, j, memo), align(seq1, seq2, i, j - 1, memo))
    };
    memo.insert((i, j), result);
    result
}

fn longest_common_subsequence(seq1: &str, seq2: &str) -> usize {
    let mut memo = HashMap::new();
    align(seq1, seq2, seq1.len(), seq2.len(), &mut memo)
}

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    println!("{}", longest_common_subsequence(seq1, seq2));
}