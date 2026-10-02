struct SequenceAligner {
    seq1: String,
    seq2: String,
}

impl SequenceAligner {
    fn new(seq1: &str, seq2: &str) -> SequenceAligner {
        SequenceAligner {
            seq1: seq1.to_string(),
            seq2: seq2.to_string(),
        }
    }

    fn score(&self, a: char, b: char) -> i32 {
        if a == b { 1 } else { -1 }
    }

    fn align(&self) -> (String, String) {
        let m = self.seq1.len();
        let n = self.seq2.len();
        let mut matrix = vec![vec![0; n + 1]; m + 1];
        for i in 1..=m {
            matrix[i][0] = i as i32;
        }
        for j in 1..=n {
            matrix[0][j] = j as i32;
        }
        for i in 1..=m {
            for j in 1..=n {
                let match_score = matrix[i - 1][j - 1] + self.score(self.seq1.chars().nth(i - 1).unwrap(), self.seq2.chars().nth(j - 1).unwrap());
                let delete_score = matrix[i - 1][j] + 1;
                let insert_score = matrix[i][j - 1] + 1;
                matrix[i][j] = match_score.min(delete_score).min(insert_score);
            }
        }
        self.traceback(&matrix, m, n)
    }

    fn traceback(&self, matrix: &Vec<Vec<i32>>, i: usize, j: usize) -> (String, String) {
        let mut align1 = String::new();
        let mut align2 = String::new();
        let mut i = i;
        let mut j = j;
        while i > 0 || j > 0 {
            if i > 0 && j > 0 && matrix[i][j] == matrix[i - 1][j - 1] + self.score(self.seq1.chars().nth(i - 1).unwrap(), self.seq2.chars().nth(j - 1).unwrap()) {
                align1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                align2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if i > 0 && matrix[i][j] == matrix[i - 1][j] + 1 {
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
    let aligner = SequenceAligner::new(seq1, seq2);
    let result = aligner.align();
    println!("Alignment 1: {}", result.0);
    println!("Alignment 2: {}", result.1);
}