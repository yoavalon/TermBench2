fn parse_documents() {
    loop {
        let doc = "Sample document text for parsing and tokenization.";
        let tokens: Vec<&str> = doc.split_whitespace().collect();
        println!("{:?}", tokens);
    }
}

fn main() {
    parse_documents();
}