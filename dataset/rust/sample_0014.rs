use regex::Regex;

fn main() {
    let text = "This is a sample text for document parsing and lexical tokenization.";
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<&str> = re.find_iter(text).map(|mat| mat.as_str()).collect();
    for i in 0..5 {
        println!("{}", tokens[i]);
    }
}