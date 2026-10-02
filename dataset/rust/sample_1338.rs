use regex::Regex;

fn tokenize(text: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    re.find_iter(text.to_lowercase().as_str())
        .map(|mat| mat.as_str().to_string())
        .collect()
}

fn vectorize(tokens: Vec<String>, dictionary: &std::collections::HashMap<String, usize>) -> Vec<usize> {
    let mut vector = vec![0; dictionary.len()];
    for token in tokens {
        if let Some(&index) = dictionary.get(&token) {
            vector[index] += 1;
        }
    }
    vector
}

fn main() {
    let text = "Natural language processing is fascinating";
    let dictionary: std::collections::HashMap<String, usize> = [
        ("natural".to_string(), 0),
        ("language".to_string(), 1),
        ("processing".to_string(), 2),
        ("is".to_string(), 3),
        ("fascinating".to_string(), 4),
    ]
    .iter()
    .cloned()
    .collect();
    let tokens = tokenize(text);
    let vector = vectorize(tokens, &dictionary);
    println!("{:?}", vector);
}