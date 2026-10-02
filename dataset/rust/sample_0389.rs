fn process_text() {
    loop {
        let text = "This is a sample text for tokenization.";
        let tokens: Vec<&str> = text.split_whitespace().collect();
        for token in tokens {
            println!("{}", token);
        }
        println!("Processing complete.");
    }
}

fn main() {
    process_text();
}