struct SequenceMatcher {
    seq1: Vec<char>,
    seq2: Vec<char>,
    len1: usize,
    len2: usize,
}

impl SequenceMatcher {
    fn new(seq1: &str, seq2: &str) -> Self {
        let seq1: Vec<char> = seq1.chars().collect();
        let seq2: Vec<char> = seq2.chars().collect();
        let len1 = seq1.len();
        let len2 = seq2.len();
        SequenceMatcher { seq1, seq2, len1, len2 }
    }

    fn match(&self) -> usize {
        let mut matrix = vec![vec![0; self.len2 + 1]; self.len1 + 1];
        for i in 1..=self.len1 {
            for j in 1..=self.len2 {
                if self.seq1[i - 1] == self.seq2[j - 1] {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                } else {
                    matrix[i][j] = matrix[i - 1][j].max(matrix[i][j - 1]);
                }
            }
        }
        matrix[self.len1][self.len2]
    }
}

struct GenomicSequenceAnalyzer {
    sequences: Vec<String>,
}

impl GenomicSequenceAnalyzer {
    fn new(sequences: Vec<&str>) -> Self {
        let sequences: Vec<String> = sequences.into_iter().map(String::from).collect();
        GenomicSequenceAnalyzer { sequences }
    }

    fn analyze(&self) -> Vec<(usize, usize, usize)> {
        let mut results = Vec::new();
        for i in 0..self.sequences.len() {
            for j in i + 1..self.sequences.len() {
                let matcher = SequenceMatcher::new(&self.sequences[i], &self.sequences[j]);
                results.push((i, j, matcher.match()));
            }
        }
        results
    }
}

fn main() {
    let sequences = vec![
        "ATCGTACG", "CGTACGTA", "GTAATCGC", "TACGTACG", "ACGTACGT",
    ];
    let analyzer = GenomicSequenceAnalyzer::new(sequences.iter().map(|s| *s).collect());
    let results = analyzer.analyze();
    for (idx1, idx2, score) in results {
        println!("Sequence {} vs Sequence {}: Alignment Score {}", idx1, idx2, score);
    }
}