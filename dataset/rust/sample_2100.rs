struct SequenceAligner {
    seq1: String,
    seq2: String,
    matrix: Vec<Vec<i32>>,
    traceback_matrix: Vec<Vec<i32>>,
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> Self {
        SequenceAligner {
            seq1: seq1.to_string(),
            seq2: seq2.to_string(),
            matrix: Vec::new(),
            traceback_matrix: Vec::new(),
        }
    }

    fn initialize_matrices(&mut self) {
        let m = self.seq1.len() + 1;
        let n = self.seq2.len() + 1;
        self.matrix = vec![vec![0; n]; m];
        self.traceback_matrix = vec![vec![0; n]; m];
        for i in 1..m {
            self.matrix[i][0] = i as i32;
            self.traceback_matrix[i][0] = 1;
        }
        for j in 1..n {
            self.matrix[0][j] = j as i32;
            self.traceback_matrix[0][j] = 2;
        }
    }

    fn fill_matrices(&mut self) {
        let m = self.seq1.len();
        let n = self.seq2.len();
        for i in 1..=m {
            for j in 1..=n {
                let match_score = self.matrix[i - 1][j - 1] + if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) { 0 } else { 1 };
                let delete_score = self.matrix[i - 1][j] + 1;
                let insert_score = self.matrix[i][j - 1] + 1;
                self.matrix[i][j] = match_score.min(delete_score).min(insert_score);
                if self.matrix[i][j] == match_score {
                    self.traceback_matrix[i][j] = 3;
                } else if self.matrix[i][j] == delete_score {
                    self.traceback_matrix[i][j] = 1;
                } else {
                    self.traceback_matrix[i][j] = 2;
                }
            }
        }
    }

    fn traceback(&self) -> (String, String) {
        let mut alignment1 = String::new();
        let mut alignment2 = String::new();
        let mut i = self.seq1.len();
        let mut j = self.seq2.len();
        while i > 0 || j > 0 {
            if self.traceback_matrix[i][j] == 3 {
                alignment1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                alignment2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if self.traceback_matrix[i][j] == 1 {
                alignment1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                alignment2.insert(0, '-');
                i -= 1;
            } else {
                alignment1.insert(0, '-');
                alignment2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                j -= 1;
            }
        }
        (alignment1, alignment2)
    }
}

fn main() {
    let seq1 = "GATTACA";
    let seq2 = "GCATGCU";
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.initialize_matrices();
    aligner.fill_matrices();
    let (alignment1, alignment2) = aligner.traceback();
    println!("{}", alignment1);
    println!("{}", alignment2);
}