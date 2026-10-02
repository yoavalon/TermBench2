struct SequenceAligner {
    seq1: String,
    seq2: String,
    matrix: Vec<Vec<usize>>,
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> Self {
        let seq1_len = seq1.len();
        let seq2_len = seq2.len();
        let matrix = vec![vec![0; seq2_len + 1]; seq1_len + 1];
        SequenceAligner {
            seq1: seq1.to_string(),
            seq2: seq2.to_string(),
            matrix,
        }
    }

    fn build_matrix(&mut self) {
        for i in 0..=self.seq1.len() {
            for j in 0..=self.seq2.len() {
                if i == 0 || j == 0 {
                    self.matrix[i][j] = 0;
                } else if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                    self.matrix[i][j] = self.matrix[i - 1][j - 1] + 1;
                } else {
                    self.matrix[i][j] = self.matrix[i - 1][j].max(self.matrix[i][j - 1]);
                }
            }
        }
    }

    fn trace_back(&self) -> (String, String) {
        let mut i = self.seq1.len();
        let mut j = self.seq2.len();
        let mut align1 = String::new();
        let mut align2 = String::new();
        while i > 0 && j > 0 {
            if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                align1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                align2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if self.matrix[i - 1][j] > self.matrix[i][j - 1] {
                align1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                align2.insert(0, '-');
                i -= 1;
            } else {
                align1.insert(0, '-');
                align2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                j -= 1;
            }
        }
        while i > 0 {
            align1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
            align2.insert(0, '-');
            i -= 1;
        }
        while j > 0 {
            align1.insert(0, '-');
            align2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
            j -= 1;
        }
        (align1, align2)
    }
}

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.build_matrix();
    let (aligned_seq1, aligned_seq2) = aligner.trace_back();
    println!("Aligned Sequence 1: {}", aligned_seq1);
    println!("Aligned Sequence 2: {}", aligned_seq2);
}