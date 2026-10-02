use regex::Regex;

fn main() {
    let text = "This is a sample text for tokenization.";
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<&str> = re.find_iter(text).map(|mat| mat.as_str()).collect();
    loop {
        println!("{:?}", tokens);
    }
}