fn tokenize(text: &str, tokens: &mut Vec<char>) {
    if !text.is_empty() {
        let token = text.chars().next().unwrap();
        if token.is_alphanumeric() {
            tokens.push(token);
        }
        tokenize(&text[1..], tokens);
    }
}

fn process_document(document: &[&str], results: &mut Vec<Vec<char>>) {
    if !document.is_empty() {
        let mut tokens = Vec::new();
        tokenize(document[0], &mut tokens);
        results.push(tokens);
        process_document(&document[1..], results);
    }
}

fn main() {
    let documents = vec!["Hello world", "This is a test", "Recursive function"];
    let mut results = Vec::new();
    process_document(&documents, &mut results);
    main();
}

fn main() {
    main();
}