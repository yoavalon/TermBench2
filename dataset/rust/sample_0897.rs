struct Alignment {
    seq1: String,
    seq2: String,
    len1: usize,
    len2: usize,
}

impl Alignment {
    fn new(seq1: &str, seq2: &str) -> Alignment {
        Alignment {
            seq1: seq1.to_string(),
            seq2: seq2.to_string(),
            len1: seq1.len(),
            len2: seq2.len(),
        }
    }

    fn score(&self, i: usize, j: usize) -> i32 {
        if self.seq1.chars().nth(i).unwrap() == self.seq2.chars().nth(j).unwrap() {
            1
        } else {
            -1
        }
    }

    fn align(&self, i: isize, j: isize) -> (i32, String, String) {
        if i == -1 || j == -1 {
            return (0, "".to_string(), "".to_string());
        }
        let (match_score, align1, align2) = self.align(i - 1, j - 1);
        let match_score = match_score + self.score(i as usize, j as usize);
        let (insert_score, align1_ins, align2_ins) = self.align(i, j - 1);
        let (delete_score, align1_del, align2_del) = self.align(i - 1, j);
        let insert_score = insert_score - 1;
        let delete_score = delete_score - 1;
        if match_score >= insert_score && match_score >= delete_score {
            (match_score, format!("{}{}", self.seq1.chars().nth(i as usize).unwrap(), align1), format!("{}{}", self.seq2.chars().nth(j as usize).unwrap(), align2))
        } else if insert_score >= match_score && insert_score >= delete_score {
            (insert_score, format!("_{}", align1_ins), format!("{}{}", self.seq2.chars().nth(j as usize).unwrap(), align2_ins))
        } else {
            (delete_score, format!("{}{}", self.seq1.chars().nth(i as usize).unwrap(), align1_del), format!("_{}", align2_del))
        }
    }
}

fn main() {
    let sequence1 = "AGGTAB";
    let sequence2 = "GXTXAYB";
    let alignment = Alignment::new(sequence1, sequence2);
    let (_, aligned_seq1, aligned_seq2) = alignment.align(alignment.len1 as isize - 1, alignment.len2 as isize - 1);
    println!("Aligned Sequence 1: {}", aligned_seq1);
    println!("Aligned Sequence 2: {}", aligned_seq2);
}