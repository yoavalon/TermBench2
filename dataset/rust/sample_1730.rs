use rand::Rng;

fn generate_sequence(length: usize) -> String {
    let mut rng = rand::thread_rng();
    (0..length)
        .map(|_| rng.choose(&['A', 'T', 'C', 'G']).unwrap())
        .collect()
}

fn align_sequences(seq1: &str, seq2: &str) -> usize {
    let mut matrix = vec![vec![0; seq2.len() + 1]; seq1.len() + 1];
    for i in 1..=seq1.len() {
        for j in 1..=seq2.len() {
            if seq1.as_bytes()[i - 1] == seq2.as_bytes()[j - 1] {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = matrix[i - 1][j].max(matrix[i][j - 1]);
            }
        }
    }
    matrix[seq1.len()][seq2.len()]
}

fn mutate_sequence(seq: &str) -> String {
    let mut rng = rand::thread_rng();
    seq.chars()
        .map(|c| {
            if rng.gen::<f64>() < 0.1 {
                *rng.choose(&['A', 'T', 'C', 'G']).unwrap()
            } else {
                c
            }
        })
        .collect()
}

struct SequenceAligner {
    seq1: String,
    seq2: String,
}

impl SequenceAligner {
    fn new(seq1: String, seq2: String) -> Self {
        SequenceAligner { seq1, seq2 }
    }

    fn update_sequences(&mut self) {
        self.seq1 = mutate_sequence(&self.seq1);
        self.seq2 = mutate_sequence(&self.seq2);
    }

    fn run_alignment(&mut self) {
        loop {
            let alignment_score = align_sequences(&self.seq1, &self.seq2);
            println!("Alignment Score: {}", alignment_score);
            self.update_sequences();
        }
    }
}

fn main() {
    let seq1 = generate_sequence(100);
    let seq2 = generate_sequence(100);
    let mut aligner = SequenceAligner::new(seq1, seq2);
    aligner.run_alignment();
}