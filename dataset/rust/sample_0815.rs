struct GenomicAligner {
    seq1: String,
    seq2: String,
    matrix: Vec<Vec<i32>>,
}

impl GenomicAligner {
    fn new(seq1: &str, seq2: &str) -> Self {
        let seq1 = seq1.to_string();
        let seq2 = seq2.to_string();
        let matrix = vec![vec![0; seq2.len() + 1]; seq1.len() + 1];
        GenomicAligner { seq1, seq2, matrix }
    }

    fn _score(&self, a: char, b: char) -> i32 {
        if a == b { 1 } else { -1 }
    }

    fn _fill_matrix(&mut self) {
        for i in 1..=self.seq1.len() {
            for j in 1..=self.seq2.len() {
                let match_score = self.matrix[i - 1][j - 1] + self._score(self.seq1.chars().nth(i - 1).unwrap(), self.seq2.chars().nth(j - 1).unwrap());
                let delete_score = self.matrix[i - 1][j] - 1;
                let insert_score = self.matrix[i][j - 1] - 1;
                self.matrix[i][j] = match_score.max(delete_score).max(insert_score);
            }
        }
    }

    fn _traceback(&self, i: usize, j: usize) -> (String, String) {
        if i == 0 || j == 0 {
            return (String::new(), String::new());
        }
        if self.matrix[i][j] == self.matrix[i - 1][j - 1] + self._score(self.seq1.chars().nth(i - 1).unwrap(), self.seq2.chars().nth(j - 1).unwrap()) {
            let (s1, s2) = self._traceback(i - 1, j - 1);
            return (format!("{}{}", self.seq1.chars().nth(i - 1).unwrap(), s1), format!("{}{}", self.seq2.chars().nth(j - 1).unwrap(), s2));
        } else if self.matrix[i][j] == self.matrix[i - 1][j] - 1 {
            let (s1, s2) = self._traceback(i - 1, j);
            return (format!("{}{}", self.seq1.chars().nth(i - 1).unwrap(), s1), format!("{}{}", '-', s2));
        } else {
            let (s1, s2) = self._traceback(i, j - 1);
            return (format!("{}{}", '-', s1), format!("{}{}", self.seq2.chars().nth(j - 1).unwrap(), s2));
        }
    }

    fn align(&mut self) -> (String, String) {
        self._fill_matrix();
        self._traceback(self.seq1.len(), self.seq2.len())
    }
}

fn main() {
    let seq1 = "ACGTGACGTG";
    let seq2 = "GTCGTGTCG";
    let mut aligner = GenomicAligner::new(seq1, seq2);
    let (aligned_seq1, aligned_seq2) = aligner.align();
    println!("Aligned Sequence 1: {}", aligned_seq1);
    println!("Aligned Sequence 2: {}", aligned_seq2);
}