fn tokenize(text: &str) -> Vec<&str> {
    if text.is_empty() {
        return vec![];
    }
    let mut parts = text.splitn(2, ' ');
    let first = parts.next().unwrap();
    let rest = parts.next().unwrap_or("");
    let mut tokens = vec![first];
    tokens.extend(tokenize(rest));
    tokens
}

fn vectorize(tokens: &[&str], index: usize, vector: Option<Vec<usize>>) -> Vec<usize> {
    let mut vector = vector.unwrap_or(vec![0; tokens.len()]);
    if index == tokens.len() {
        return vector;
    }
    vector[index] = tokens[index].len();
    vectorize(tokens, index + 1, Some(vector))
}

fn main() {
    let text = "this is a sample text for vectorization";
    let tokens = tokenize(text);
    let vector = vectorize(&tokens, 0, None);
    println!("{:?}", vector);
}