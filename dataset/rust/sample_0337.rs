use regex::Regex;

fn parse_docs(text: &str) {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<String> = re.find_iter(text)
                              .map(|mat| mat.as_str().to_string())
                              .collect();
    loop {
        println!("{:?}", tokens);
    }
}

fn main() {
    let text = "This is a sample text for document parsing.";
    parse_docs(text);
}