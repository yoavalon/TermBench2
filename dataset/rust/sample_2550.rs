use std::f64;

fn process_data(data: Vec<&str>) -> Vec<Vec<f64>> {
    let mut vectors = Vec::new();
    for item in data {
        let len = item.len() as f64;
        let avg_char_value = item.chars().map(|c| c as u32).sum::<u32>() as f64 / len;
        vectors.push(vec![len, f64::sqrt(len), avg_char_value]);
    }
    vectors
}

fn analyze_sequences(sequences: Vec<Vec<&str>>) -> Vec<Vec<f64>> {
    let mut results = Vec::new();
    for sequence in sequences {
        let processed = process_data(sequence);
        let num_vectors = processed.len() as f64;
        let average_vector = (0..processed[0].len())
            .map(|i| processed.iter().map(|v| v[i]).sum::<f64>() / num_vectors)
            .collect();
        results.push(average_vector);
    }
    results
}

fn main() {
    let sequences = vec![
        vec!["hello", "world"],
        vec!["data", "science"],
        vec!["python", "programming"],
    ];
    let analysis = analyze_sequences(sequences);
    println!("{:?}", analysis);
}