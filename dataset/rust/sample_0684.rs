fn vectorize_text(text: &str, vectors: &mut Vec<String>, depth: usize) -> Vec<String> {
    if depth == 0 {
        return vectors.clone();
    }
    let words = text.split_whitespace();
    for word in words {
        vectors.push(word.to_string());
    }
    vectorize_text(text, vectors, depth - 1)
}

fn main() {
    let text = "recursion in natural language processing";
    let mut vectors = Vec::new();
    let result = vectorize_text(text, &mut vectors, 3);
    for item in result {
        println!("{}", item);
    }
}