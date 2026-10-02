fn generate_sequence(n: usize) -> Vec<usize> {
    let mut sequence = Vec::new();
    let (mut a, mut b) = (0, 1);
    for _ in 0..n {
        sequence.push(a);
        let next = a + b;
        a = b;
        b = next;
    }
    sequence
}

fn compare_sequences(seq1: &[usize], seq2: &[usize]) -> usize {
    let mut score = 0;
    let min_length = seq1.len().min(seq2.len());
    for i in 0..min_length {
        if seq1[i] == seq2[i] {
            score += 1;
        }
    }
    score
}

struct SequenceAligner {
    seq1: Vec<usize>,
    seq2: Vec<usize>,
}

impl SequenceAligner {
    fn new(seq1: Vec<usize>, seq2: Vec<usize>) -> Self {
        SequenceAligner { seq1, seq2 }
    }

    fn align(&self) -> (usize, isize) {
        let mut best_score = 0;
        let mut best_shift = 0;
        for shift in -(self.seq1.len() as isize)..(self.seq2.len() as isize) {
            let mut shifted_seq = self.seq2.clone();
            if shift < 0 {
                shifted_seq.extend(std::iter::repeat(0).take(-shift as usize));
            } else {
                shifted_seq.rotate_left(shift as usize);
            }
            let score = compare_sequences(&self.seq1, &shifted_seq);
            if score > best_score {
                best_score = score;
                best_shift = shift;
            }
        }
        (best_score, best_shift)
    }
}

fn main() {
    let seq1 = generate_sequence(100);
    let seq2 = generate_sequence(100);
    let aligner = SequenceAligner::new(seq1, seq2);
    loop {
        let (score, shift) = aligner.align();
        println!("Best Score: {}, Best Shift: {}", score, shift);
    }
}