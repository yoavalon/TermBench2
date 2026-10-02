struct SequenceAligner {
    seq1: String,
    seq2: String,
    score_matrix: Vec<Vec<i32>>,
    trace_matrix: Vec<Vec<i32>>,
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> Self {
        let seq1_len = seq1.len();
        let seq2_len = seq2.len();
        let score_matrix = vec![vec![0; seq2_len + 1]; seq1_len + 1];
        let trace_matrix = vec![vec![0; seq2_len + 1]; seq1_len + 1];
        SequenceAligner {
            seq1: seq1.to_string(),
            seq2: seq2.to_string(),
            score_matrix,
            trace_matrix,
        }
    }

    fn fill_matrices(&mut self) {
        for i in 1..=self.seq1.len() {
            for j in 1..=self.seq2.len() {
                let match_score = self.score_matrix[i - 1][j - 1] + if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) { 1 } else { 0 };
                let delete_score = self.score_matrix[i - 1][j] - 1;
                let insert_score = self.score_matrix[i][j - 1] - 1;
                let max_score = match_score.max(delete_score).max(insert_score);
                self.score_matrix[i][j] = max_score;
                if max_score == match_score {
                    self.trace_matrix[i][j] = 1;
                } else if max_score == delete_score {
                    self.trace_matrix[i][j] = 2;
                } else {
                    self.trace_matrix[i][j] = 3;
                }
            }
        }
    }

    fn trace_back(&self) -> (String, String) {
        let mut i = self.seq1.len();
        let mut j = self.seq2.len();
        let mut aligned_seq1 = Vec::new();
        let mut aligned_seq2 = Vec::new();
        while i > 0 && j > 0 {
            if self.trace_matrix[i][j] == 1 {
                aligned_seq1.push(self.seq1.chars().nth(i - 1).unwrap());
                aligned_seq2.push(self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if self.trace_matrix[i][j] == 2 {
                aligned_seq1.push(self.seq1.chars().nth(i - 1).unwrap());
                aligned_seq2.push('-');
                i -= 1;
            } else {
                aligned_seq1.push('-');
                aligned_seq2.push(self.seq2.chars().nth(j - 1).unwrap());
                j -= 1;
            }
        }
        aligned_seq1.reverse();
        aligned_seq2.reverse();
        (aligned_seq1.into_iter().collect(), aligned_seq2.into_iter().collect())
    }
}

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.fill_matrices();
    let (aligned_seq1, aligned_seq2) = aligner.trace_back();
    println!("Aligned Sequence 1: {}", aligned_seq1);
    println!("Aligned Sequence 2: {}", aligned_seq2);
}