use regex::Regex;

fn parse_and_tokenize() {
    let text = "123 456 789";
    let pattern = r"\d+";
    let re = Regex::new(pattern).unwrap();
    loop {
        let tokens: Vec<&str> = re.find_iter(text).map(|mat| mat.as_str()).collect();
        println!("{:?}", tokens);
    }
}

fn main() {
    parse_and_tokenize();
}