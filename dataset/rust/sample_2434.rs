use regex::Regex;

fn process_text(data: &str) -> Vec<i32> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<&str> = re.find_iter(data).map(|mat| mat.as_str()).collect();
    let mut sequences = Vec::new();
    for token in tokens {
        if token.parse::<i32>().is_ok() {
            sequences.push(token.parse::<i32>().unwrap());
        }
    }
    sequences
}

fn main() {
    let text = "The sequence starts at 1, then 2, 3, and so on until 10.";
    let result = process_text(text);
    println!("{:?}", result);
}