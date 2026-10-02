struct Sequencer {
    sequence: Vec<char>,
    length: usize,
}

impl Sequencer {
    fn new(sequence: &str) -> Sequencer {
        Sequencer {
            sequence: sequence.chars().collect(),
            length: sequence.len(),
        }
    }

    fn align(&self, other: &Sequencer) -> usize {
        let mut score = 0;
        for i in 0..std::cmp::min(self.length, other.length) {
            if self.sequence[i] == other.sequence[i] {
                score += 1;
            }
        }
        score
    }

    fn normalize(&self) -> Vec<f64> {
        self.sequence.iter().map(|&x| x as f64 / self.length as f64).collect()
    }
}

struct Aligner {
    sequences: Vec<String>,
    sequencers: Vec<Sequencer>,
}

impl Aligner {
    fn new(sequences: Vec<&str>) -> Aligner {
        Aligner {
            sequences: sequences.into_iter().map(String::from).collect(),
            sequencers: sequences.into_iter().map(Sequencer::new).collect(),
        }
    }

    fn pairwise_alignment(&self) -> Vec<usize> {
        let mut scores = Vec::new();
        for i in 0..self.sequencers.len() {
            for j in i + 1..self.sequencers.len() {
                let score = self.sequencers[i].align(&self.sequencers[j]);
                scores.push(score);
            }
        }
        scores
    }

    fn average_score(&self) -> f64 {
        let total: usize = self.pairwise_alignment().iter().sum();
        total as f64 / self.sequencers.len() as f64
    }
}

fn main() {
    let sequences = vec!["ATCG", "ATCC", "ATCGT", "ATCGA"];
    let aligner = Aligner::new(sequences);
    let average_score = aligner.average_score();
    let normalized_scores: Vec<Vec<f64>> = aligner.sequencers.iter().map(|seq| seq.normalize()).collect();
    println!("Average Alignment Score: {}", average_score);
    for (i, seq) in normalized_scores.iter().enumerate() {
        println!("Normalized Sequence {}: {:?}", i + 1, seq);
    }
}