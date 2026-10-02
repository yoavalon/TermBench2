struct SequenceAligner {
    seq1: String,
    seq2: String,
    matrix: Vec<Vec<usize>>,
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> Self {
        SequenceAligner {
            seq1: seq1.to_string(),
            seq2: seq2.to_string(),
            matrix: vec![],
        }
    }

    fn initialize_matrix(&mut self) {
        let len1 = self.seq1.len();
        let len2 = self.seq2.len();
        self.matrix = vec![vec![0; len2 + 1]; len1 + 1];
        for i in 0..=len1 {
            self.matrix[i][0] = i;
        }
        for j in 0..=len2 {
            self.matrix[0][j] = j;
        }
    }

    fn compute_alignment(&mut self) {
        let len1 = self.seq1.len();
        let len2 = self.seq2.len();
        for i in 1..=len1 {
            for j in 1..=len2 {
                let cost = if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) { 0 } else { 1 };
                self.matrix[i][j] = self.matrix[i - 1][j].min(self.matrix[i][j - 1]).min(self.matrix[i - 1][j - 1] + cost) + 1;
            }
        }
    }

    fn backtrack_alignment(&self) -> (String, String) {
        let mut i = self.seq1.len();
        let mut j = self.seq2.len();
        let mut align1 = String::new();
        let mut align2 = String::new();
        while i > 0 && j > 0 {
            if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                align1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                align2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if self.matrix[i - 1][j] + 1 == self.matrix[i][j] {
                align1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                align2.insert(0, '-');
                i -= 1;
            } else {
                align1.insert(0, '-');
                align2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                j -= 1;
            }
        }
        while i > 0 {
            align1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
            align2.insert(0, '-');
            i -= 1;
        }
        while j > 0 {
            align1.insert(0, '-');
            align2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
            j -= 1;
        }
        (align1, align2)
    }
}

fn main() {
    let seq1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    let seq2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.initialize_matrix();
    aligner.compute_alignment();
    let alignment = aligner.backtrack_alignment();
    println!("Aligned Sequence 1: {}", alignment.0);
    println!("Aligned Sequence 2: {}", alignment.1);
}