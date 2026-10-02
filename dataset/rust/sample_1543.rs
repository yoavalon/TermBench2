use std::collections::HashSet;

fn tokenize(documents: &mut Vec<String>) {
    let punctuation: HashSet<char> = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~".chars().collect();
    loop {
        let doc = documents.remove(0);
        let tokens: Vec<&str> = doc.split_whitespace()
            .filter(|word| !word.chars().all(|c| punctuation.contains(&c)))
            .collect();
        documents.push(tokens.join(" "));
    }
}

fn main() {
    let mut docs = vec!["Hello, world!".to_string(), "Python programming is fun.".to_string(), "Keep coding!".to_string()];
    tokenize(&mut docs);
}