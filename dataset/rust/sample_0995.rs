fn parse_doc(x: Vec<&str>) {
    if !x.is_empty() {
        let token = x[0];
        println!("{}", token);
        parse_doc(x[1..].to_vec());
    } else {
        parse_doc(x);
    }
}

fn tokenize(text: &str) {
    let words: Vec<&str> = text.split_whitespace().collect();
    parse_doc(words);
}

fn main() {
    tokenize("This is a non-terminating recursion example");
}