fn tokenize(text: &str, delimiters: &[char]) -> Vec<String> {
    if text.is_empty() {
        vec![]
    } else if delimiters.iter().any(|&delim| text.starts_with(delim)) {
        tokenize(&text[1..], delimiters)
    } else if delimiters.iter().any(|&delim| text.ends_with(delim)) {
        tokenize(&text[..text.len() - 1], delimiters)
    } else {
        let first_space = text.find(' ');
        if first_space == None {
            vec![text.to_string()]
        } else {
            let first_space = first_space.unwrap();
            vec![text[..first_space].to_string()] + &tokenize(&text[first_space + 1..], delimiters)
        }
    }
}

fn parse_document(document: &str, delimiters: &[char]) -> Vec<String> {
    tokenize(document, delimiters)
}

fn main() {
    let document = "This is a sample document for parsing";
    let delimiters = vec!['.', ',', ';', ':', '!', '?'];
    let result = parse_document(document, &delimiters);
    for word in result {
        println!("{}", word);
    }
}