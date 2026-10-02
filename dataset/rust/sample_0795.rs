fn tokenize(document: &str, tokens: &mut Vec<&str>) {
    if document.is_empty() {
        return;
    }
    let (word, _, rest) = document.partition(' ');
    tokens.push(word);
    tokenize(rest, tokens);
}

fn parse_document(text: &str) -> Vec<Vec<&str>> {
    let paragraphs = text.split('\n');
    let mut result = Vec::new();
    for paragraph in paragraphs {
        let mut words = Vec::new();
        tokenize(paragraph, &mut words);
        result.push(words);
    }
    result
}

fn main() {
    let text = "Hello world\nThis is a test document";
    println!("{:?}", parse_document(text));
}