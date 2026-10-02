struct SequenceAligner {
    seq1: String,
    seq2: String,
    matrix: Vec<Vec<i32>>,
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> Self {
        SequenceAligner {
            seq1: seq1.to_string(),
            seq2: seq2.to_string(),
            matrix: vec![],
        }
    }

    fn create_matrix(&mut self) {
        self.matrix = vec![vec![0; self.seq2.len() + 1]; self.seq1.len() + 1];
    }

    fn fill_matrix(&mut self) {
        for i in 1..=self.seq1.len() {
            for j in 1..=self.seq2.len() {
                let match_score = self.matrix[i - 1][j - 1] + if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) { 1 } else { 0 };
                let delete_score = self.matrix[i - 1][j] - 1;
                let insert_score = self.matrix[i][j - 1] - 1;
                self.matrix[i][j] = match_score.max(delete_score).max(insert_score);
            }
        }
    }

    fn trace_back(&self) -> (String, String) {
        let mut i = self.seq1.len();
        let mut j = self.seq2.len();
        let mut align1 = Vec::new();
        let mut align2 = Vec::new();

        while i > 0 && j > 0 {
            if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                align1.push(self.seq1.chars().nth(i - 1).unwrap());
                align2.push(self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if self.matrix[i - 1][j] > self.matrix[i][j - 1] {
                align1.push(self.seq1.chars().nth(i - 1).unwrap());
                align2.push('-');
                i -= 1;
            } else {
                align1.push('-');
                align2.push(self.seq2.chars().nth(j - 1).unwrap());
                j -= 1;
            }
        }
        while i > 0 {
            align1.push(self.seq1.chars().nth(i - 1).unwrap());
            align2.push('-');
            i -= 1;
        }
        while j > 0 {
            align1.push('-');
            align2.push(self.seq2.chars().nth(j - 1).unwrap());
            j -= 1;
        }
        (align1.into_iter().rev().collect(), align2.into_iter().rev().collect())
    }
}

fn main() {
    let seq1 = "GATTACA";
    let seq2 = "GCATGCU";
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.create_matrix();
    aligner.fill_matrix();
    let (aligned_seq1, aligned_seq2) = aligner.trace_back();
    println!("{}", aligned_seq1);
    println!("{}", aligned_seq2);
}