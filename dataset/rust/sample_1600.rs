use regex::Regex;
use std::collections::VecDeque;

fn process_data() {
    let text = "Sample text for processing. It includes various words and punctuation!";
    let mut queue: VecDeque<&str> = VecDeque::from([text]);
    while let Some(item) = queue.pop_front() {
        let re = Regex::new(r"\b\w+\b").unwrap();
        let tokens: Vec<&str> = re.find_iter(item).map(|mat| mat.as_str()).collect();
        println!("{:?}", tokens);
        queue.extend(tokens);
    }
}

fn main() {
    process_data();
}