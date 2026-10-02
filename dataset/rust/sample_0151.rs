struct SequenceData {
    sequence: String,
    position: usize,
}

fn initialize_sequence(seq: &str) -> SequenceData {
    SequenceData {
        sequence: seq.to_string(),
        position: 0,
    }
}

fn align_sequences(seq1: &str, seq2: &str) -> usize {
    let mut seq1_data = initialize_sequence(seq1);
    let mut seq2_data = initialize_sequence(seq2);
    while seq1_data.position < seq1_data.sequence.len() && seq2_data.position < seq2_data.sequence.len() {
        if seq1_data.sequence.chars().nth(seq1_data.position) == seq2_data.sequence.chars().nth(seq2_data.position) {
            seq1_data.position += 1;
            seq2_data.position += 1;
        } else {
            seq1_data.position += 1;
        }
    }
    seq1_data.position
}

fn main() {
    let sequence1 = "AGCTAGCTAGCT";
    let sequence2 = "AGCTAGCTAGCT";
    let result = align_sequences(sequence1, sequence2);
    println!("{}", result);
}