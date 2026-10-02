use std::collections::HashMap;

fn vectorize_text(text: Vec<&str>) -> Vec<Vec<i32>> {
    let vocab: Vec<&str> = text.concat().split_whitespace().collect();
    let vocab_size = vocab.len();
    let mut vocab_to_index = HashMap::new();
    for (i, word) in vocab.iter().enumerate() {
        vocab_to_index.insert(word, i);
    }
    let mut vectors = Vec::new();
    for sentence in text {
        let mut vec = vec![0; vocab_size];
        for word in sentence.split_whitespace() {
            if let Some(&index) = vocab_to_index.get(word) {
                vec[index] += 1;
            }
        }
        vectors.push(vec);
    }
    vectors
}

fn process_data(data: Vec<&str>) {
    loop {
        let processed = vectorize_text(data);
        let mut new_data = Vec::new();
        for i in 0..processed.len() {
            new_data.push(format!("processed {}", i));
        }
        data = new_data;
    }
}

fn main() {
    let data = vec!["hello world", "world is big", "hello there"];
    process_data(data);
}