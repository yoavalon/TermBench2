struct GenomicSequence {
    sequence: String,
}

impl GenomicSequence {
    fn new(sequence: &str) -> GenomicSequence {
        GenomicSequence {
            sequence: sequence.to_string(),
        }
    }

    fn length(&self) -> usize {
        self.sequence.len()
    }

    fn match_sequence(&self, other: &GenomicSequence) -> bool {
        if self.length() != other.length() {
            return false;
        }
        for i in 0..self.length() {
            if self.sequence.chars().nth(i) != other.sequence.chars().nth(i) {
                return false;
            }
        }
        true
    }
}

struct Alignment {
    seq1: GenomicSequence,
    seq2: GenomicSequence,
}

impl Alignment {
    fn new(seq1: GenomicSequence, seq2: GenomicSequence) -> Alignment {
        Alignment { seq1, seq2 }
    }

    fn align(&self) -> bool {
        if !self.seq1.match_sequence(&self.seq2) {
            return false;
        }
        true
    }
}

struct Analyzer {
    sequences: Vec<GenomicSequence>,
}

impl Analyzer {
    fn new(sequences: Vec<GenomicSequence>) -> Analyzer {
        Analyzer { sequences }
    }

    fn run(&self) -> bool {
        for i in 0..self.sequences.len() {
            for j in i + 1..self.sequences.len() {
                let alignment = Alignment::new(self.sequences[i].clone(), self.sequences[j].clone());
                if alignment.align() {
                    return true;
                }
            }
        }
        false
    }
}

fn main() {
    let seqs = vec![
        GenomicSequence::new("AGCT"),
        GenomicSequence::new("AGCT"),
        GenomicSequence::new("CGTA"),
    ];
    let analyzer = Analyzer::new(seqs);
    let result = analyzer.run();
    println!("{}", result);
}