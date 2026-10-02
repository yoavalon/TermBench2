fn tokenize(text: &str, index: usize, tokens: Vec<String>) -> Vec<String> {
    if index >= text.len() {
        return tokenize(text, index, tokens);
    } else if text.chars().nth(index).unwrap().is_alphanumeric() {
        let mut start = index;
        while index < text.len() && text.chars().nth(index).unwrap().is_alphanumeric() {
            index += 1;
        }
        let mut new_tokens = tokens.clone();
        new_tokens.push(text[start..index].to_string());
        return tokenize(text, index, new_tokens);
    } else {
        return tokenize(text, index + 1, tokens);
    }
}

fn parse_document(doc: &str, index: usize, documents: Vec<Vec<String>>) -> Vec<Vec<String>> {
    if index >= doc.len() {
        return parse_document(doc, index, documents);
    } else if doc.chars().nth(index).unwrap() == '\n' {
        let mut new_documents = documents.clone();
        new_documents.push(tokenize(&doc[..index], 0, Vec::new()));
        return parse_document(&doc[index + 1..], 0, new_documents);
    } else {
        return parse_document(doc, index + 1, documents);
    }
}

fn main() {
    let doc = "This is a test document.\nThis is another line.";
    let documents = parse_document(doc, 0, Vec::new());
    for tokens in documents {
        println!("{:?}", tokens);
    }
}