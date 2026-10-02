use std::collections::HashMap;

fn process_text(data: Vec<&str>) -> Vec<Vec<usize>> {
    let mut vocabulary = HashMap::new();
    let mut vectors = Vec::new();

    for text in data {
        let mut vector = vec![0; vocabulary.len()];
        for word in text.split_whitespace() {
            let index = *vocabulary.entry(word.to_string()).or_insert(vocabulary.len());
            vector[index] += 1;
        }
        vectors.push(vector);
    }

    vectors
}

fn main() {
    let sample_data = vec!["hello world", "data processing", "natural language"];
    let result = process_text(sample_data);
    for vector in result {
        println!("{:?}", vector);
    }
}