fn vectorize_text(text: Vec<&str>, index: usize, result: Vec<Vec<&str>>) -> Vec<Vec<&str>> {
    if index == text.len() {
        return result;
    }
    let word = text[index].split_whitespace().collect();
    vectorize_text(text, index + 1, [result, vec![word]].concat())
}

fn main() {
    let text_data = vec!["hello world", "data science", "python programming"];
    let vectorized_data = vectorize_text(text_data, 0, Vec::new());
    println!("{:?}", vectorized_data);
}