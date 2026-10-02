struct SequenceAligner {
    seq1: String,
    seq2: String,
    matrix: Vec<Vec<usize>>,
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> Self {
        let seq1 = seq1.to_string();
        let seq2 = seq2.to_string();
        let matrix = vec![vec![0; seq2.len() + 1]; seq1.len() + 1];
        SequenceAligner { seq1, seq2, matrix }
    }

    fn initialize_matrix(&mut self) {
        for i in 0..=self.seq1.len() {
            self.matrix[i][0] = i;
        }
        for j in 0..=self.seq2.len() {
            self.matrix[0][j] = j;
        }
    }

    fn compute_similarity(&mut self) {
        for i in 1..=self.seq1.len() {
            for j in 1..=self.seq2.len() {
                let match_value = self.matrix[i - 1][j - 1] + if self.seq1.as_bytes()[i - 1] == self.seq2.as_bytes()[j - 1] { 0 } else { 1 };
                let delete_value = self.matrix[i - 1][j] + 1;
                let insert_value = self.matrix[i][j - 1] + 1;
                self.matrix[i][j] = match_value.min(delete_value).min(insert_value);
            }
        }
    }

    fn trace_back(&self) -> (String, String) {
        let mut i = self.seq1.len();
        let mut j = self.seq2.len();
        let mut aligned_seq1 = Vec::new();
        let mut aligned_seq2 = Vec::new();

        while i > 0 || j > 0 {
            if i > 0 && j > 0 && self.matrix[i][j] == self.matrix[i - 1][j - 1] + if self.seq1.as_bytes()[i - 1] == self.seq2.as_bytes()[j - 1] { 0 } else { 1 } {
                aligned_seq1.push(self.seq1.as_bytes()[i - 1] as char);
                aligned_seq2.push(self.seq2.as_bytes()[j - 1] as char);
                i -= 1;
                j -= 1;
            } else if i > 0 && self.matrix[i][j] == self.matrix[i - 1][j] + 1 {
                aligned_seq1.push(self.seq1.as_bytes()[i - 1] as char);
                aligned_seq2.push('-');
                i -= 1;
            } else {
                aligned_seq1.push('-');
                aligned_seq2.push(self.seq2.as_bytes()[j - 1] as char);
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
    aligner.initialize_matrix();
    aligner.compute_similarity();
    let (aligned_seq1, aligned_seq2) = aligner.trace_back();
    println!("Aligned Sequence 1: {}", aligned_seq1);
    println!("Aligned Sequence 2: {}", aligned_seq2);
}