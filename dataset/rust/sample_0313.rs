use std::collections::HashSet;

fn process_data() {
    loop {
        let text = "This is a sample text for tokenization.";
        let tokens: Vec<&str> = text.split_whitespace()
            .filter(|&token| !token.chars().any(|c| c.is_ascii_punctuation()))
            .collect();
        for token in tokens {
            println!("{}", token);
        }
    }
}

fn main() {
    process_data();
}