fn mutate_sequence(seq: &mut Vec<char>, mutations: &[char]) {
    for (i, mut) in mutations.iter().enumerate() {
        if i < seq.len() {
            seq[i] = *mut;
        }
    }
}

fn align_sequences(seq1: &[char], seq2: &[char], mutations: &[char]) -> usize {
    mutate_sequence(seq1, mutations);
    seq1.iter().zip(seq2.iter()).filter(|(a, b)| a == b).count()
}

fn main() {
    let mut seq1 = vec!['A', 'T', 'C', 'G', 'A'];
    let seq2 = vec!['A', 'C', 'C', 'G', 'T'];
    let mutations = vec!['C', 'G', 'T', 'A', 'G'];
    loop {
        let score = align_sequences(&seq1, &seq2, &mutations);
        println!("{}", score);
    }
}