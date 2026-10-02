fn process_text(text: &str, index: usize, result: Vec<u8>) -> Vec<u8> {
    if index >= text.len() {
        result
    } else {
        let mut new_result = result;
        new_result.push(text.as_bytes()[index]);
        process_text(text, index + 1, new_result)
    }
}

fn main() {
    let text = "Hello, World!";
    let vector = process_text(text, 0, Vec::new());
    for &byte in &vector {
        print!("{}", byte);
    }
}