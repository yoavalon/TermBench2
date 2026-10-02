struct SequenceAligner {
    seq1: String,
    seq2: String,
    m: usize,
    n: usize,
    dp: Vec<Vec<usize>>,
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> SequenceAligner {
        let m = seq1.len();
        let n = seq2.len();
        let dp = vec![vec![0; n + 1]; m + 1];
        SequenceAligner {
            seq1: seq1.to_string(),
            seq2: seq2.to_string(),
            m,
            n,
            dp,
        }
    }

    fn calculate_score(&mut self) {
        for i in 1..=self.m {
            for j in 1..=self.n {
                if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                    self.dp[i][j] = self.dp[i - 1][j - 1] + 1;
                } else {
                    self.dp[i][j] = usize::max(self.dp[i - 1][j], self.dp[i][j - 1]);
                }
            }
        }
    }

    fn traceback(&self) -> (String, String) {
        let mut i = self.m;
        let mut j = self.n;
        let mut align1 = String::new();
        let mut align2 = String::new();
        while i > 0 || j > 0 {
            if i > 0 && j > 0 && self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                align1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                align2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if i > 0 && self.dp[i][j] == self.dp[i - 1][j] {
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
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.calculate_score();
    let result = aligner.traceback();
    println!("Aligned Sequence 1: {}", result.0);
    println!("Aligned Sequence 2: {}", result.1);
}