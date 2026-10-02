fn process_text(text: &str, depth: usize, max_depth: usize) -> String {
    if depth >= max_depth {
        return text.to_string();
    }
    let words: Vec<&str> = text.split_whitespace().collect();
    let processed_words: Vec<String> = words.into_iter().map(|word| word.to_lowercase()).collect();
    let processed_text: String = processed_words.join(" ");
    format!("{} {}", processed_text, process_text(text, depth + 1, max_depth))
}

fn main() {
    let input_text = "Hello World! This is a Test.";
    let result = process_text(input_text, 0, 5);
    println!("{}", result);
}