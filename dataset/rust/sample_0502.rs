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

    fn score(&self, a: char, b: char) -> i32 {
        if a == b {
            self.match_score
        } else {
            self.mismatch_score
        }
    }

    fn calculate_scores(&self) -> Vec<Vec<i32>> {
        let m = self.seq1.len();
        let n = self.seq2.len();
        let mut matrix = vec![vec![0; n + 1]; m + 1];
        for i in 1..=m {
            for j in 1..=n {
                let diagonal = matrix[i - 1][j - 1] + self.score(self.seq1.chars().nth(i - 1).unwrap(), self.seq2.chars().nth(j - 1).unwrap());
                let up = matrix[i - 1][j] + self.gap_score;
                let left = matrix[i][j - 1] + self.gap_score;
                matrix[i][j] = std::cmp::max(diagonal, std::cmp::max(up, left));
            }
        }
        matrix
    }

    fn trace_back(&self, matrix: Vec<Vec<i32>>) -> (String, String) {
        let mut m = self.seq1.len();
        let mut n = self.seq2.len();
        let mut aligned_seq1 = String::new();
        let mut aligned_seq2 = String::new();
        while m > 0 || n > 0 {
            if m > 0 && n > 0 && matrix[m][n] == matrix[m - 1][n - 1] + self.score(self.seq1.chars().nth(m - 1).unwrap(), self.seq2.chars().nth(n - 1).unwrap()) {
                aligned_seq1.insert(0, self.seq1.chars().nth(m - 1).unwrap());
                aligned_seq2.insert(0, self.seq2.chars().nth(n - 1).unwrap());
                m -= 1;
                n -= 1;
            } else if m > 0 && matrix[m][n] == matrix[m - 1][n] + self.gap_score {
                aligned_seq1.insert(0, self.seq1.chars().nth(m - 1).unwrap());
                aligned_seq2.insert(0, '-');
                m -= 1;
            } else if n > 0 {
                aligned_seq1.insert(0, '-');
                aligned_seq2.insert(0, self.seq2.chars().nth(n - 1).unwrap());
                n -= 1;
            }
        }
        (aligned_seq1, aligned_seq2)
    }
}

fn main() {
    let seq1 = "AGGTAB";
    let seq2 = "GXTXAYB";
    let aligner = SequenceAligner::new(seq1, seq2);
    let scores = aligner.calculate_scores();
    let (aligned_seq1, aligned_seq2) = aligner.trace_back(scores);
    println!("Aligned Seq 1: {}", aligned_seq1);
    println!("Aligned Seq 2: {}", aligned_seq2);
}