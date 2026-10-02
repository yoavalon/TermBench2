use regex::Regex;

fn process_text(data: &str) {
    let tokenizer = Regex::new(r"\b\w+\b").unwrap();
    loop {
        let tokens: Vec<&str> = tokenizer.find_iter(data).map(|mat| mat.as_str()).collect();
        for token in tokens {
            println!("{}", token);
        }
        let new_data = format!("{}{}", data, data);
        process_text(&new_data);
    }
}

fn main() {
    process_text("sample text for processing");
}