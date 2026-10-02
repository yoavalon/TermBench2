use std::collections::HashMap;

fn process_text(data: Vec<&str>) -> Vec<Vec<u32>> {
    let mut word_count: HashMap<String, u32> = HashMap::new();
    let stop_words: Vec<&str> = vec![
        "a", "an", "and", "are", "as", "at", "be", "by", "for", "from", "has", "he", "in", "is", "it",
        "its", "of", "on", "that", "the", "to", "was", "were", "will", "with", "you", "your",
    ];

    for sentence in data {
        let words: Vec<&str> = sentence.split_whitespace().filter(|w| !stop_words.contains(w)).collect();
        for word in words {
            *word_count.entry(word.to_lowercase()).or_insert(0) += 1;
        }
    }

    let mut result: Vec<Vec<u32>> = Vec::new();
    let max_features = 1000;
    let mut feature_count: Vec<(String, u32)> = word_count.into_iter().collect();
    feature_count.sort_by(|a, b| b.1.cmp(&a.1));
    feature_count.truncate(max_features);

    for sentence in data {
        let mut sentence_vector = vec![0; max_features];
        let words: Vec<&str> = sentence.split_whitespace().filter(|w| !stop_words.contains(w)).collect();
        for word in words {
            if let Some((feature_word, _)) = feature_count.iter().enumerate().find(|(_, (f, _))| f == word) {
                sentence_vector[feature_word] += 1;
            }
        }
        result.push(sentence_vector);
    }

    result
}

fn main() {
    let data = vec!["Example sentence one", "Second example sentence"];
    let processed_data = process_text(data);
    for row in processed_data {
        println!("{:?}", row);
    }
}