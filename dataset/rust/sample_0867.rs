struct Alignment {
    seq1: String,
    seq2: String,
    matrix: Vec<Vec<isize>>,
    result: (String, String),
}

impl Alignment {
    fn new(seq1: &str, seq2: &str) -> Alignment {
        let seq1 = seq1.to_string();
        let seq2 = seq2.to_string();
        let mut matrix = vec![vec![0; seq2.len() + 1]; seq1.len() + 1];
        let mut alignment = Alignment {
            seq1,
            seq2,
            matrix,
            result: (String::new(), String::new()),
        };
        alignment.fill_matrix();
        alignment.traceback();
        alignment
    }

    fn fill_matrix(&mut self) {
        for i in 1..=self.seq1.len() {
            for j in 1..=self.seq2.len() {
                let match_value = if self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1) {
                    self.matrix[i - 1][j - 1] + 1
                } else {
                    0
                };
                let delete_value = self.matrix[i - 1][j] - 1;
                let insert_value = self.matrix[i][j - 1] - 1;
                self.matrix[i][j] = match_value.max(delete_value).max(insert_value);
            }
        }
    }

    fn traceback(&mut self) {
        let (mut i, mut j) = (self.seq1.len(), self.seq2.len());
        let mut align1 = String::new();
        let mut align2 = String::new();
        while i > 0 || j > 0 {
            if i > 0 && j > 0 && (self.matrix[i][j] == self.matrix[i - 1][j - 1] + 1) && (self.seq1.chars().nth(i - 1) == self.seq2.chars().nth(j - 1)) {
                align1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                align2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                i -= 1;
                j -= 1;
            } else if i > 0 && (j == 0 || self.matrix[i][j] == self.matrix[i - 1][j] - 1) {
                align1.insert(0, self.seq1.chars().nth(i - 1).unwrap());
                align2.insert(0, '-');
                i -= 1;
            } else {
                align1.insert(0, '-');
                align2.insert(0, self.seq2.chars().nth(j - 1).unwrap());
                j -= 1;
            }
        }
        self.result = (align1, align2);
    }
}

fn main() {
    let seq1 = "AGTACGCA";
    let seq2 = "GTTAC";
    let alignment = Alignment::new(seq1, seq2);
    println!("Sequence 1: {}", alignment.result.0);
    println!("Sequence 2: {}", alignment.result.1);
}