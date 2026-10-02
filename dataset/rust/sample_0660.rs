fn vectorize_text(text: &str, index: usize, result: Option<Vec<u8>>) -> Vec<u8> {
    let mut result = result.unwrap_or_else(Vec::new);
    if index < text.len() {
        result.push(text.as_bytes()[index]);
        return vectorize_text(text, index + 1, Some(result));
    }
    result
}

fn main() {
    println!("{:?}", vectorize_text("hello", 0, None));
}