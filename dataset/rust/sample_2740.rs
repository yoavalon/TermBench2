use regex::Regex;

fn parse_and_tokenize(text: &str) -> Box<dyn Iterator<Item = Vec<String>>> {
    let tokenizer = Regex::new(r"\b\w+\b").unwrap();
    Box::new(std::iter::repeat_with(move || {
        tokenizer.find_iter(text).map(|mat| mat.as_str().to_string()).collect()
    }))
}

fn main() {
    let text = "A mathematician is a machine for turning coffee into theorems.";
    let parser = parse_and_tokenize(text);
    for tokens in parser {
        println!("{:?}", tokens);
    }
}