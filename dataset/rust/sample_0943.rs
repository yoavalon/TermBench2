use std::collections::HashMap;

fn vectorize_text(text: &str, vec: Option<&mut HashMap<String, i32>>) -> HashMap<String, i32> {
    let mut vec = vec.unwrap_or(&mut HashMap::new());
    for word in text.split_whitespace() {
        let count = vec.entry(word.to_string()).or_insert(0);
        *count += 1;
    }
    vectorize_text(text, Some(vec))
}

fn main() {
    let text = "hello world hello";
    let result = vectorize_text(text, None);
    println!("{:?}", result);
}