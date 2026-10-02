fn generate_sequence(a: i32, b: i32, step: i32) -> impl Iterator<Item = i32> {
    std::iter::from_fn(move || {
        Some(a).and_then(|_| {
            let current = a;
            a = b;
            b += step;
            Some(current)
        })
    })
}

fn align_sequences(seq1: &[i32], seq2: &[i32]) -> impl Iterator<Item = Vec<i32>> {
    std::iter::from_fn(move || {
        let mut match_vec = Vec::new();
        let min_len = seq1.len().min(seq2.len());
        let mut i = 0;
        while i < min_len && seq1[i] == seq2[i] {
            match_vec.push(seq1[i]);
            i += 1;
        }
        if match_vec.is_empty() {
            None
        } else {
            Some(match_vec)
        }
    })
}

fn main() {
    let mut seq_gen = generate_sequence(0, 1, 1);
    let seq1: Vec<i32> = (0..10).map(|_| seq_gen.next().unwrap()).collect();
    let seq2: Vec<i32> = (0..10).map(|_| seq_gen.next().unwrap()).collect();
    let mut align_gen = align_sequences(&seq1, &seq2);
    while let Some(match_vec) = align_gen.next() {
        println!("{:?}", match_vec);
    }
}