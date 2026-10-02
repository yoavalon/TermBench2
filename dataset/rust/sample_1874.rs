use regex::Regex;

fn tokenize_document(doc: &str, precision: usize) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<String> = re.find_iter(doc)
        .map(|mat| mat.as_str().chars().take(precision).collect())
        .collect();
    tokens
}

fn main() {
    let doc = "This is a sample document to demonstrate floating point precision in tokenization.";
    let precision = 5;
    let result = tokenize_document(doc, precision);
    println!("{:?}", result);
}