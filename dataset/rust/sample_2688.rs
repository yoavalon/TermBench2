struct SequenceAligner {
    seq1: String,
    seq2: String,
    matrix: Vec<Vec<usize>>,
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
                if self.seq1.as_bytes()[i - 1] == self.seq2.as_bytes()[j - 1] {
                    self.matrix[i][j] = self.matrix[i - 1][j - 1] + 1;
                } else {
                    self.matrix[i][j] = self.matrix[i - 1][j].max(self.matrix[i][j - 1]);
                }
            }
        }
    }

    fn trace_back(&self) -> String {
        let mut i = self.seq1.len();
        let mut j = self.seq2.len();
        let mut alignment = Vec::new();
        while i > 0 && j > 0 {
            if self.seq1.as_bytes()[i - 1] == self.seq2.as_bytes()[j - 1] {
                alignment.push(self.seq1.as_bytes()[i - 1]);
                i -= 1;
                j -= 1;
            } else if self.matrix[i - 1][j] > self.matrix[i][j - 1] {
                i -= 1;
            } else {
                j -= 1;
            }
        }
        alignment.reverse();
        String::from_utf8(alignment).unwrap()
    }
}

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.fill_matrix();
    let result = aligner.trace_back();
    println!("Aligned sequence: {}", result);
}