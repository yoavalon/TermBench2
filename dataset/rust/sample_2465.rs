use regex::Regex;

fn process_sequence(text: &str) -> Vec<i32> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<&str> = re.find_iter(text).map(|mat| mat.as_str()).collect();
    let sequence: Vec<i32> = tokens.iter().filter_map(|&token| token.parse().ok()).collect();
    sequence.into_iter().take(10).collect()
}

fn main() {
    let data = "The sequence starts with 1, 2, 3, and continues with 4, 5, 6, 7, 8, 9, 10.";
    let result = process_sequence(data);
    println!("{:?}", result);
}