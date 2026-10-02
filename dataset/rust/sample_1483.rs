struct SequenceAligner {
    seq1: String,
    seq2: String,
    score_matrix: Vec<Vec<isize>>,
    traceback_matrix: Vec<Vec<usize>>,
    max_score: isize,
    max_position: (usize, usize),
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> Self {
        SequenceAligner {
            seq1: seq1.to_string(),
            seq2: seq2.to_string(),
            score_matrix: Vec::new(),
            traceback_matrix: Vec::new(),
            max_score: 0,
            max_position: (0, 0),
        }
    }

    fn initialize_matrices(&mut self) {
        let len1 = self.seq1.len();
        let len2 = self.seq2.len();
        for i in 0..=len1 {
            self.score_matrix.push(vec![0; len2 + 1]);
            self.traceback_matrix.push(vec![0; len2 + 1]);
        }
    }

    fn fill_matrices(&mut self) {
        for i in 1..=self.seq1.len() {
            for j in 1..=self.seq2.len() {
                let match_score = self.score_matrix[i - 1][j - 1] + if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) { 1 } else { -1 };
                let delete_score = self.score_matrix[i - 1][j] - 1;
                let insert_score = self.score_matrix[i][j - 1] - 1;
                self.score_matrix[i][j] = match_score.max(delete_score).max(insert_score);
                if self.score_matrix[i][j] == match_score {
                    self.traceback_matrix[i][j] = 1;
                } else if self.score_matrix[i][j] == delete_score {
                    self.traceback_matrix[i][j] = 2;
                } else {
                    self.traceback_matrix[i][j] = 3;
                }
                if self.score_matrix[i][j] > self.max_score {
                    self.max_score = self.score_matrix[i][j];
                    self.max_position = (i, j);
                }
            }
        }
    }

    fn backtrack(&self) -> (String, String) {
        let mut aligned_seq1 = Vec::new();
        let mut aligned_seq2 = Vec::new();
        let mut i = self.max_position.0;
        let mut j = self.max_position.1;
        while i > 0 && j > 0 {
            if self.traceback_matrix[i][j] == 1 {
                aligned_seq1.push(self.seq1.chars().nth(i - 1).unwrap());
                aligned_seq2.push(self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if self.traceback_matrix[i][j] == 2 {
                aligned_seq1.push(self.seq1.chars().nth(i - 1).unwrap());
                aligned_seq2.push('-');
                i -= 1;
            } else {
                aligned_seq1.push('-');
                aligned_seq2.push(self.seq2.chars().nth(j - 1).unwrap());
                j -= 1;
            }
        }
        (aligned_seq1.into_iter().rev().collect(), aligned_seq2.into_iter().rev().collect())
    }
}

fn main() {
    let seq1 = "AGCTG";
    let seq2 = "CGTAT";
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.initialize_matrices();
    aligner.fill_matrices();
    let (aligned_seq1, aligned_seq2) = aligner.backtrack();
    println!("{}", aligned_seq1);
    println!("{}", aligned_seq2);
}