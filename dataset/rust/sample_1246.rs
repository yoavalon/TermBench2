use regex::Regex;

fn parse_document(data: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<String> = re.find_iter(data)
                               .map(|mat| mat.as_str().to_string())
                               .collect();
    tokens.into_iter().take(10).collect()
}

fn main() {
    let text = "This is a sample text document for parsing and tokenization.";
    let result = parse_document(text);
    for token in result {
        println!("{}", token);
    }
}