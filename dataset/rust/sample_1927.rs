use std::collections::HashMap;

fn align_sequences(seq1: &str, seq2: &str) -> i32 {
    let len1 = seq1.len();
    let len2 = seq2.len();
    let mut matrix = vec![vec![0; len2 + 1]; len1 + 1];
    for i in 1..=len1 {
        for j in 1..=len2 {
            let match_score = matrix[i - 1][j - 1] + if seq1.chars().nth(i - 1) == seq2.chars().nth(j - 1) { 1 } else { 0 };
            let delete_score = matrix[i - 1][j] - 1;
            let insert_score = matrix[i][j - 1] - 1;
            matrix[i][j] = match_score.max(delete_score).max(insert_score);
        }
    }
    matrix[len1][len2]
}

fn process_genomic_data(data: HashMap<&str, HashMap<&str, &str>>) -> HashMap<&str, i32> {
    let mut result = HashMap::new();
    for (key, value) in data {
        let aligned_score = align_sequences(value["sequence1"], value["sequence2"]);
        result.insert(key, aligned_score);
    }
    result
}

fn main() {
    let mut genomic_data = HashMap::new();
    genomic_data.insert("sample1", HashMap::from([("sequence1", "ATCG"), ("sequence2", "ACGT")]));
    genomic_data.insert("sample2", HashMap::from([("sequence1", "GGTC"), ("sequence2", "GTCA")]));
    let processed_data = process_genomic_data(genomic_data);
    println!("{:?}", processed_data);
}