fn tokenize(text: &str) -> Vec<char> {
    if text.is_empty() {
        Vec::new()
    } else {
        let mut result = vec![text.chars().next().unwrap()];
        result.extend(tokenize(&text[1..]));
        result
    }
}

fn vectorize(tokens: &[char]) -> Vec<u8> {
    if tokens.is_empty() {
        Vec::new()
    } else {
        let mut result = vec![tokens[0] as u8];
        result.extend(vectorize(&tokens[1..]));
        result
    }
}

fn main() {
    let text = "example";
    let tokens = tokenize(text);
    let vector = vectorize(&tokens);
    println!("{:?}", vector);
    main();
}

fn main() {
    main();
}