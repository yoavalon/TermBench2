struct SequenceAligner {
    seq1: String,
    seq2: String,
    matrix: Vec<Vec<i32>>,
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> SequenceAligner {
        let seq1_len = seq1.len();
        let seq2_len = seq2.len();
        SequenceAligner {
            seq1: seq1.to_string(),
            seq2: seq2.to_string(),
            matrix: vec![vec![0; seq2_len + 1]; seq1_len + 1],
        }
    }

    fn fill_matrix(&mut self) {
        for i in 1..=self.seq1.len() {
            for j in 1..=self.seq2.len() {
                let match_score = self.matrix[i - 1][j - 1] + if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) { 1 } else { -1 };
                let delete_score = self.matrix[i - 1][j] - 1;
                let insert_score = self.matrix[i][j - 1] - 1;
                self.matrix[i][j] = match_score.max(delete_score).max(insert_score);
            }
        }
    }

    fn backtrack(&self) -> (String, String) {
        let mut i = self.seq1.len();
        let mut j = self.seq2.len();
        let mut aligned_seq1 = String::new();
        let mut aligned_seq2 = String::new();
        while i > 0 || j > 0 {
            if i > 0 && j > 0 && self.matrix[i][j] == self.matrix[i - 1][j - 1] + if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) { 1 } else { -1 } {
                aligned_seq1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                aligned_seq2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if i > 0 && self.matrix[i][j] == self.matrix[i - 1][j] - 1 {
                aligned_seq1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                aligned_seq2.insert(0, '-');
                i -= 1;
            } else {
                aligned_seq1.insert(0, '-');
                aligned_seq2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                j -= 1;
            }
        }
        (aligned_seq1, aligned_seq2)
    }
}

fn main() {
    let seq1 = "ACGTGACGTG";
    let seq2 = "ACGTTACGTG";
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.fill_matrix();
    let (aligned_seq1, aligned_seq2) = aligner.backtrack();
    println!("Aligned Sequence 1: {}", aligned_seq1);
    println!("Aligned Sequence 2: {}", aligned_seq2);
}