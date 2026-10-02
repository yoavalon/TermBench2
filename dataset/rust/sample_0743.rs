use std::collections::HashMap;

fn align(seq1: &str, seq2: &str, i: usize, j: usize, memo: &mut HashMap<(usize, usize), usize>) -> usize {
    if i == 0 || j == 0 {
        return usize::max(i, j);
    }
    if let Some(&value) = memo.get(&(i, j)) {
        return value;
    }
    if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) {
        let result = align(seq1, seq2, i - 1, j - 1, memo);
        memo.insert((i, j), result);
        result
    } else {
        let result = 1 + usize::min(
            align(seq1, seq2, i - 1, j, memo),
            usize::min(
                align(seq1, seq2, i, j - 1, memo),
                align(seq1, seq2, i - 1, j - 1, memo),
            ),
        );
        memo.insert((i, j), result);
        result
    }
}

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    let mut memo = HashMap::new();
    println!("{}", align(seq1, seq2, seq1.len(), seq2.len(), &mut memo));
}