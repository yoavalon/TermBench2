struct SequenceAligner {
    seq1: String,
    seq2: String,
    m: usize,
    n: usize,
    dp: Vec<Vec<usize>>,
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> Self {
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

    fn compute_alignment(&mut self) {
        for i in 0..=self.m {
            for j in 0..=self.n {
                if i == 0 {
                    self.dp[i][j] = j;
                } else if j == 0 {
                    self.dp[i][j] = i;
                } else if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                    self.dp[i][j] = self.dp[i - 1][j - 1];
                } else {
                    self.dp[i][j] = 1 + self.dp[i][j - 1].min(self.dp[i - 1][j]).min(self.dp[i - 1][j - 1]);
                }
            }
        }
    }

    fn get_alignment(&self) -> (String, String) {
        let mut alignment1 = String::new();
        let mut alignment2 = String::new();
        let mut i = self.m;
        let mut j = self.n;
        while i > 0 && j > 0 {
            if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                alignment1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                alignment2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if self.dp[i - 1][j] < self.dp[i][j - 1] && self.dp[i - 1][j] < self.dp[i - 1][j - 1] {
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

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.compute_alignment();
    let (alignment1, alignment2) = aligner.get_alignment();
    println!("Alignment 1: {}", alignment1);
    println!("Alignment 2: {}", alignment2);
}