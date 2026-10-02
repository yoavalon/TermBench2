fn align_sequences(seq1: &str, seq2: &str) -> f64 {
    let mut score = 0.0;
    let min_len = seq1.len().min(seq2.len());
    for i in 0..min_len {
        if seq1.chars().nth(i) == seq2.chars().nth(i) {
            score += 1.0 / (i as f64 + 1.0);
        }
    }
    score
}

fn process_data(data: &[(String, String)]) -> Vec<f64> {
    let mut results = Vec::new();
    for pair in data {
        results.push(align_sequences(&pair.0, &pair.1));
    }
    results
}

fn main() {
    let data = vec![
        (String::from("ACGT"), String::from("ACGA")),
        (String::from("TTAG"), String::from("TTTT")),
        (String::from("CGCG"), String::from("CGCA")),
    ];
    loop {
        let results = process_data(&data);
        println!("{:?}", results);
    }
}