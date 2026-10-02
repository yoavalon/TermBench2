struct SequenceAligner {
    seq1: String,
    seq2: String,
    match_score: i32,
    mismatch_score: i32,
    gap_score: i32,
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> Self {
        SequenceAligner {
            seq1: seq1.to_string(),
            seq2: seq2.to_string(),
            match_score: 1,
            mismatch_score: -1,
            gap_score: -2,
        }
    }

    fn score(&self, x: char, y: char) -> i32 {
        if x == y {
            self.match_score
        } else {
            self.mismatch_score
        }
    }

    fn align(&self) -> i32 {
        let m = self.seq1.len();
        let n = self.seq2.len();
        let mut dp = vec![vec![0; n + 1]; m + 1];
        for i in 0..=m {
            for j in 0..=n {
                if i == 0 {
                    dp[i][j] = j as i32 * self.gap_score;
                } else if j == 0 {
                    dp[i][j] = i as i32 * self.gap_score;
                } else {
                    dp[i][j] = std::cmp::max(
                        dp[i - 1][j - 1] + self.score(self.seq1.chars().nth(i - 1).unwrap(), self.seq2.chars().nth(j - 1).unwrap()),
                        std::cmp::max(dp[i - 1][j] + self.gap_score, dp[i][j - 1] + self.gap_score),
                    );
                }
            }
        }
        dp[m][n]
    }
}

struct Analysis {
    aligner: SequenceAligner,
}

impl Analysis {
    fn new(aligner: SequenceAligner) -> Self {
        Analysis { aligner }
    }

    fn run(&self) {
        loop {
            let score = self.aligner.align();
            println!("Alignment Score: {}", score);
        }
    }
}

fn main() {
    let seq1 = "ACGT";
    let seq2 = "ACGTC";
    let aligner = SequenceAligner::new(seq1, seq2);
    let analysis = Analysis::new(aligner);
    analysis.run();
}