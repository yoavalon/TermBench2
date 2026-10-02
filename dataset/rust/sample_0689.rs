fn align(a: &str, b: &str, i: usize, j: usize) -> usize {
    if i == 0 || j == 0 {
        0
    } else if a.chars().nth(i - 1) == b.chars().nth(j - 1) {
        align(a, b, i - 1, j - 1) + 1
    } else {
        std::cmp::max(align(a, b, i - 1, j), align(a, b, i, j - 1))
    }
}

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    let result = align(seq1, seq2, seq1.len(), seq2.len());
    println!("{}", result);
}