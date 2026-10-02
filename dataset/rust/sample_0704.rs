use std::collections::HashMap;

fn align(seq1: &str, seq2: &str, i: usize, j: usize, mem: &mut HashMap<(usize, usize), usize>) -> usize {
    if i == 0 || j == 0 {
        return 0;
    }
    if let Some(&result) = mem.get(&(i, j)) {
        return result;
    }
    if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) {
        let result = 1 + align(seq1, seq2, i - 1, j - 1, mem);
        mem.insert((i, j), result);
        result
    } else {
        let result = align(seq1, seq2, i - 1, j, mem).max(align(seq1, seq2, i, j - 1, mem)).unwrap_or(0);
        mem.insert((i, j), result);
        result
    }
}

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    let i = seq1.len();
    let j = seq2.len();
    let mut mem = HashMap::new();
    println!("{}", align(seq1, seq2, i, j, &mut mem));
}