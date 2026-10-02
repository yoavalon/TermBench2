struct SequenceMatcher {
    seq1: String,
    seq2: String,
    matrix: Vec<Vec<usize>>,
}

impl SequenceMatcher {
    fn new(seq1: &str, seq2: &str) -> Self {
        let len1 = seq1.len();
        let len2 = seq2.len();
        let matrix = vec![vec![0; len2 + 1]; len1 + 1];
        SequenceMatcher {
            seq1: seq1.to_string(),
            seq2: seq2.to_string(),
            matrix,
        }
    }

    fn compute_alignment(&mut self) {
        for i in 1..=self.seq1.len() {
            for j in 1..=self.seq2.len() {
                let match_value = if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                    self.matrix[i - 1][j - 1] + 1
                } else {
                    0
                };
                let delete_value = self.matrix[i - 1][j];
                let insert_value = self.matrix[i][j - 1];
                self.matrix[i][j] = match_value.max(delete_value).max(insert_value);
            }
        }
    }

    fn trace_back(&self) -> (String, String) {
        let mut alignment1 = String::new();
        let mut alignment2 = String::new();
        let mut i = self.seq1.len();
        let mut j = self.seq2.len();
        while i > 0 && j > 0 {
            if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                alignment1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                alignment2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if self.matrix[i - 1][j] >= self.matrix[i][j - 1] {
                alignment1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                alignment2.insert(0, '-');
                i -= 1;
            } else {
                alignment1.insert(0, '-');
                alignment2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                j -= 1;
            }
        }
        while i > 0 {
            alignment1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
            alignment2.insert(0, '-');
            i -= 1;
        }
        while j > 0 {
            alignment1.insert(0, '-');
            alignment2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
            j -= 1;
        }
        (alignment1, alignment2)
    }
}

fn process_sequences(seq1: &str, seq2: &str) -> (String, String) {
    let mut matcher = SequenceMatcher::new(seq1, seq2);
    matcher.compute_alignment();
    matcher.trace_back()
}

fn main() {
    let seq1 = "AGCTG";
    let seq2 = "AGGCT";
    let (aligned_seq1, aligned_seq2) = process_sequences(seq1, seq2);
    println!("{}", aligned_seq1);
    println!("{}", aligned_seq2);
}