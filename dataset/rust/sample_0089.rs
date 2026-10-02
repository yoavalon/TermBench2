use regex::Regex;

fn tokenize_text(text: &str) {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens = re.find_iter(text).map(|mat| mat.as_str()).collect::<Vec<&str>>();
    for (i, token) in tokens.iter().enumerate() {
        if i >= 10 {
            break;
        }
        println!("{}", token);
    }
}

fn main() {
    let text_data = "This is a sample text for tokenization and parsing.";
    tokenize_text(text_data);
}