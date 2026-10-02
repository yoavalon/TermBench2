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

    fn initialize_matrix(&mut self) {
        for i in 0..=self.seq1.len() {
            self.matrix[i][0] = i;
        }
        for j in 0..=self.seq2.len() {
            self.matrix[0][j] = j;
        }
    }

    fn fill_matrix(&mut self) {
        for i in 1..=self.seq1.len() {
            for j in 1..=self.seq2.len() {
                let cost = if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                    0
                } else {
                    1
                };
                self.matrix[i][j] = self.matrix[i - 1][j].min(self.matrix[i][j - 1]).min(self.matrix[i - 1][j - 1] + cost) + 1;
            }
        }
    }

    fn trace_back(&self) -> (String, String) {
        let (mut i, mut j) = (self.seq1.len(), self.seq2.len());
        let (mut align1, mut align2) = (String::new(), String::new());
        while i > 0 || j > 0 {
            if i > 0 && j > 0 && self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                align1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                align2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if i > 0 && self.matrix[i][j] == self.matrix[i - 1][j] + 1 {
                align1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                align2.insert(0, '-');
                i -= 1;
            } else {
                align1.insert(0, '-');
                align2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                j -= 1;
            }
        }
        (align1, align2)
    }
}

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.initialize_matrix();
    aligner.fill_matrix();
    let aligned_sequences = aligner.trace_back();
    println!("Aligned Sequence 1: {}", aligned_sequences.0);
    println!("Aligned Sequence 2: {}", aligned_sequences.1);
}