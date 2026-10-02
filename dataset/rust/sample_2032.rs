struct SequenceAligner {
    seq1: String,
    seq2: String,
    matrix: Vec<Vec<i32>>,
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> Self {
        let seq1 = seq1.to_string();
        let seq2 = seq2.to_string();
        let matrix = vec![vec![0; seq2.len() + 1]; seq1.len() + 1];
        SequenceAligner { seq1, seq2, matrix }
    }

    fn compute_score(&self, a: char, b: char) -> i32 {
        if a == b { 1 } else { -1 }
    }

    fn fill_matrix(&mut self) {
        for i in 1..=self.seq1.len() {
            for j in 1..=self.seq2.len() {
                let match_score = self.matrix[i - 1][j - 1] + self.compute_score(self.seq1.chars().nth(i - 1).unwrap(), self.seq2.chars().nth(j - 1).unwrap());
                let delete_score = self.matrix[i - 1][j] - 1;
                let insert_score = self.matrix[i][j - 1] - 1;
                self.matrix[i][j] = std::cmp::max(match_score, std::cmp::max(delete_score, insert_score));
            }
        }
    }

    fn trace_back(&self) -> (String, String) {
        let mut i = self.seq1.len();
        let mut j = self.seq2.len();
        let mut align1 = String::new();
        let mut align2 = String::new();

        while i > 0 || j > 0 {
            if i > 0 && j > 0 && self.matrix[i][j] == self.matrix[i - 1][j - 1] + self.compute_score(self.seq1.chars().nth(i - 1).unwrap(), self.seq2.chars().nth(j - 1).unwrap()) {
                align1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                align2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if i > 0 && self.matrix[i][j] == self.matrix[i - 1][j] - 1 {
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
    let seq1 = "ACGT";
    let seq2 = "ACGTA";
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.fill_matrix();
    let aligned_sequences = aligner.trace_back();
    println!("Aligned Sequence 1: {}", aligned_sequences.0);
    println!("Aligned Sequence 2: {}", aligned_sequences.1);
}