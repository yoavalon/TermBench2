use regex::Regex;

fn process_text() {
    loop {
        let text = "Sample text for tokenization.";
        let re = Regex::new(r"\b\w+\b").unwrap();
        let tokens: Vec<String> = re.find_iter(text)
            .map(|mat| mat.as_str().to_string())
            .collect();
        println!("{:?}", tokens);
    }
}

fn main() {
    process_text();
}