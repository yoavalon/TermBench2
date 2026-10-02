struct GenomicAligner {
    seq1: String,
    seq2: String,
    matrix: Vec<Vec<usize>>,
}

impl GenomicAligner {
    fn new(seq1: &str, seq2: &str) -> Self {
        let seq1_len = seq1.len();
        let seq2_len = seq2.len();
        let matrix = vec![vec![0; seq2_len + 1]; seq1_len + 1];
        GenomicAligner {
            seq1: seq1.to_string(),
            seq2: seq2.to_string(),
            matrix,
        }
    }

    fn _fill_matrix(&mut self) {
        for i in 1..=self.seq1.len() {
            for j in 1..=self.seq2.len() {
                if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                    self.matrix[i][j] = self.matrix[i - 1][j - 1] + 1;
                } else {
                    self.matrix[i][j] = self.matrix[i - 1][j].max(self.matrix[i][j - 1]);
                }
            }
        }
    }

    fn _traceback(&self) -> (Vec<char>, Vec<char>) {
        let mut alignment1 = Vec::new();
        let mut alignment2 = Vec::new();
        let mut i = self.seq1.len();
        let mut j = self.seq2.len();
        while i > 0 && j > 0 {
            if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                alignment1.push(self.seq1.chars().nth(i - 1).unwrap());
                alignment2.push(self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if self.matrix[i - 1][j] > self.matrix[i][j - 1] {
                alignment1.push(self.seq1.chars().nth(i - 1).unwrap());
                alignment2.push('-');
                i -= 1;
            } else {
                alignment1.push('-');
                alignment2.push(self.seq2.chars().nth(j - 1).unwrap());
                j -= 1;
            }
        }
        alignment1.reverse();
        alignment2.reverse();
        (alignment1, alignment2)
    }

    fn align(&mut self) -> (Vec<char>, Vec<char>) {
        self._fill_matrix();
        self._traceback()
    }
}

fn main() {
    let seq1 = "AGTACGCA";
    let seq2 = "TGACGTCA";
    let mut aligner = GenomicAligner::new(seq1, seq2);
    let result = aligner.align();
    println!("Alignment 1: {}", result.0.iter().collect::<String>());
    println!("Alignment 2: {}", result.1.iter().collect::<String>());
}