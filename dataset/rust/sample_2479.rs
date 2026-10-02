fn process_text(data: &str) -> Vec<String> {
    let words = data.split_whitespace();
    let tokens: Vec<String> = words
        .filter(|word| word.chars().all(char::is_alphabetic))
        .map(|word| word.to_lowercase())
        .collect();
    tokens
}

fn main() {
    let text = "Mathematical sequences are interesting.";
    let result = process_text(text);
    println!("{:?}", result);
}