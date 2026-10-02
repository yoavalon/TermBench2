struct SequenceAligner {
    seq1: String,
    seq2: String,
    matrix: Vec<Vec<i32>>,
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> Self {
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
                let match_score = if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                    self.matrix[i - 1][j - 1] + 1
                } else {
                    0
                };
                self.matrix[i][j] = match_score.max(self.matrix[i - 1][j]).max(self.matrix[i][j - 1]);
            }
        }
    }

    fn traceback(&self) -> (String, String) {
        let mut aligned_seq1 = Vec::new();
        let mut aligned_seq2 = Vec::new();
        let mut i = self.seq1.len();
        let mut j = self.seq2.len();
        while i > 0 || j > 0 {
            if i > 0 && j > 0 && self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                aligned_seq1.push(self.seq1.chars().nth(i - 1).unwrap());
                aligned_seq2.push(self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if i > 0 && self.matrix[i][j] == self.matrix[i - 1][j] {
                aligned_seq1.push(self.seq1.chars().nth(i - 1).unwrap());
                aligned_seq2.push('-');
                i -= 1;
            } else {
                aligned_seq1.push('-');
                aligned_seq2.push(self.seq2.chars().nth(j - 1).unwrap());
                j -= 1;
            }
        }
        (aligned_seq1.iter().rev().collect(), aligned_seq2.iter().rev().collect())
    }
}

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.fill_matrix();
    let (aligned_seq1, aligned_seq2) = aligner.traceback();
    println!("{}", aligned_seq1);
    println!("{}", aligned_seq2);
}