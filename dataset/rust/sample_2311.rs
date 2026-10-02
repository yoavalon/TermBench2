fn align_sequences(seq1: &str, seq2: &str) -> Vec<Vec<i32>> {
    let length1 = seq1.len();
    let length2 = seq2.len();
    let mut matrix = vec![vec![0; length2 + 1]; length1 + 1];
    for i in 1..=length1 {
        for j in 1..=length2 {
            if seq1.as_bytes()[i - 1] == seq2.as_bytes()[j - 1] {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = matrix[i - 1][j].max(matrix[i][j - 1]);
            }
        }
    }
    matrix
}

fn backtrack(matrix: &Vec<Vec<i32>>, seq1: &str, seq2: &str) -> (String, String) {
    let mut i = seq1.len();
    let mut j = seq2.len();
    let mut aligned_seq1 = String::new();
    let mut aligned_seq2 = String::new();
    while i > 0 && j > 0 {
        if seq1.as_bytes()[i - 1] == seq2.as_bytes()[j - 1] {
            aligned_seq1.insert(0, seq1.as_bytes()[i - 1] as char);
            aligned_seq2.insert(0, seq2.as_bytes()[j - 1] as char);
            i -= 1;
            j -= 1;
        } else if matrix[i - 1][j] > matrix[i][j - 1] {
            aligned_seq1.insert(0, seq1.as_bytes()[i - 1] as char);
            aligned_seq2.insert(0, '-');
            i -= 1;
        } else {
            aligned_seq1.insert(0, '-');
            aligned_seq2.insert(0, seq2.as_bytes()[j - 1] as char);
            j -= 1;
        }
    }
    while i > 0 {
        aligned_seq1.insert(0, seq1.as_bytes()[i - 1] as char);
        aligned_seq2.insert(0, '-');
        i -= 1;
    }
    while j > 0 {
        aligned_seq1.insert(0, '-');
        aligned_seq2.insert(0, seq2.as_bytes()[j - 1] as char);
        j -= 1;
    }
    (aligned_seq1, aligned_seq2)
}

fn main() {
    let seq1 = "ACGTGACGTG";
    let seq2 = "GTCGTGTCGT";
    let matrix = align_sequences(seq1, seq2);
    let (aligned_seq1, aligned_seq2) = backtrack(&matrix, seq1, seq2);
    println!("{}", aligned_seq1);
    println!("{}", aligned_seq2);
    main();
}

fn main() {
    main();
}