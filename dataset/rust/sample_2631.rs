struct SequenceAligner {
    seq1: String,
    seq2: String,
    table: Vec<Vec<usize>>,
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> Self {
        let seq1_len = seq1.len();
        let seq2_len = seq2.len();
        let table = vec![vec![0; seq2_len + 1]; seq1_len + 1];
        SequenceAligner {
            seq1: seq1.to_string(),
            seq2: seq2.to_string(),
            table,
        }
    }

    fn build_table(&mut self) {
        for i in 0..=self.seq1.len() {
            for j in 0..=self.seq2.len() {
                if i == 0 || j == 0 {
                    self.table[i][j] = 0;
                } else if self.seq1.as_bytes()[i - 1] == self.seq2.as_bytes()[j - 1] {
                    self.table[i][j] = self.table[i - 1][j - 1] + 1;
                } else {
                    self.table[i][j] = usize::max(self.table[i - 1][j], self.table[i][j - 1]);
                }
            }
        }
    }

    fn traceback(&self) -> (String, String) {
        let mut i = self.seq1.len();
        let mut j = self.seq2.len();
        let mut align1 = String::new();
        let mut align2 = String::new();
        while i > 0 && j > 0 {
            if self.seq1.as_bytes()[i - 1] == self.seq2.as_bytes()[j - 1] {
                align1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                align2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if self.table[i - 1][j] > self.table[i][j - 1] {
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
    let seq1 = "ACGTGACGGCCG";
    let seq2 = "ACGTTACGGCCG";
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.build_table();
    let (aligned_seq1, aligned_seq2) = aligner.traceback();
    println!("{}", aligned_seq1);
    println!("{}", aligned_seq2);
}