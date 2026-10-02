struct SequenceAligner {
    seq1: String,
    seq2: String,
    matrix: Vec<Vec<usize>>,
    score_matrix: Vec<Vec<isize>>,
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> Self {
        let seq1_len = seq1.len();
        let seq2_len = seq2.len();
        SequenceAligner {
            seq1: seq1.to_string(),
            seq2: seq2.to_string(),
            matrix: vec![vec![0; seq2_len + 1]; seq1_len + 1],
            score_matrix: vec![vec![0; seq2_len + 1]; seq1_len + 1],
        }
    }

    fn initialize_matrices(&mut self) {
        for i in 0..=self.seq1.len() {
            self.matrix[i][0] = i;
            self.score_matrix[i][0] = -(i as isize) * 2;
        }
        for j in 0..=self.seq2.len() {
            self.matrix[0][j] = j;
            self.score_matrix[0][j] = -(j as isize) * 2;
        }
    }

    fn calculate_scores(&mut self) {
        for i in 1..=self.seq1.len() {
            for j in 1..=self.seq2.len() {
                let match_score = self.score_matrix[i - 1][j - 1] + if self.seq1.as_bytes()[i - 1] == self.seq2.as_bytes()[j - 1] { 1 } else { -1 };
                let delete_score = self.score_matrix[i - 1][j] - 2;
                let insert_score = self.score_matrix[i][j - 1] - 2;
                self.score_matrix[i][j] = match_score.max(delete_score).max(insert_score);
            }
        }
    }

    fn trace_back(&self) -> (String, String) {
        let mut i = self.seq1.len();
        let mut j = self.seq2.len();
        let mut aligned_seq1 = String::new();
        let mut aligned_seq2 = String::new();

        while i > 0 || j > 0 {
            if i > 0 && j > 0 && self.score_matrix[i][j] == self.score_matrix[i - 1][j - 1] + if self.seq1.as_bytes()[i - 1] == self.seq2.as_bytes()[j - 1] { 1 } else { -1 } {
                aligned_seq1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                aligned_seq2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if i > 0 && self.score_matrix[i][j] == self.score_matrix[i - 1][j] - 2 {
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
    let seq1 = "GATTACA";
    let seq2 = "GATTCACA";
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.initialize_matrices();
    aligner.calculate_scores();
    let (aligned_seq1, aligned_seq2) = aligner.trace_back();
    println!("Aligned Sequence 1: {}", aligned_seq1);
    println!("Aligned Sequence 2: {}", aligned_seq2);
}