fn tokenize(text: &str, depth: usize) -> Vec<Vec<String>> {
    if depth == 0 {
        return vec![];
    }
    let words: Vec<&str> = text.split_whitespace().collect();
    let mut result = Vec::new();
    for word in words {
        let mut sub_tokens = tokenize(word, depth - 1);
        sub_tokens.insert(0, word.to_string());
        result.push(sub_tokens);
    }
    result
}

fn vectorize(tokens: &Vec<Vec<String>>, depth: usize) -> Vec<usize> {
    if depth == 0 {
        return vec![];
    }
    let mut vector = vec![tokens.len()];
    for token in tokens {
        vector.extend(vectorize(token, depth - 1));
    }
    vector
}

fn main() {
    let text = "Recursive vectorization";
    let depth = 2;
    let tokens = tokenize(text, depth);
    let vector = vectorize(&tokens, depth);
    println!("{:?}", vector);
}