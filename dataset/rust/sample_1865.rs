use regex::Regex;

fn parse_and_tokenize(text: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens = re.find_iter(text).map(|mat| mat.as_str()).collect::<Vec<&str>>();
    tokens.into_iter().map(|token| {
        if token.replace('.', "", 1).chars().all(|c| c.is_digit(10)) {
            token.parse::<f64>().unwrap().to_string()
        } else {
            token.to_string()
        }
    }).collect()
}

fn main() {
    let text = "The value of pi is approximately 3.14159. The number 2.718 is also significant.";
    let result = parse_and_tokenize(text);
    println!("{:?}", result);
}