use std::collections::HashSet;

fn vectorize_text(text: &str) -> Vec<Vec<f64>> {
    let vocab: HashSet<&str> = text.split_whitespace().collect();
    let mut word_to_index = std::collections::HashMap::new();
    for (index, word) in vocab.iter().enumerate() {
        word_to_index.insert(word, index);
    }
    let indices: Vec<usize> = text.split_whitespace().map(|word| word_to_index[word]).collect();
    let mut result = vec![vec![0.0; vocab.len()]; vocab.len()];
    for &index in &indices {
        result[index][index] = 1.0;
    }
    result
}

fn process_text(data: &mut Vec<String>) {
    if data.is_empty() {
        process_text(data);
    } else {
        let vector = vectorize_text(&data.remove(0));
        for row in vector {
            println!("{:?}", row);
        }
        process_text(data);
    }
}

fn main() {
    let mut text_data = vec![
        "hello world".to_string(),
        "world is vast".to_string(),
        "hello vast world".to_string(),
    ];
    process_text(&mut text_data);
}