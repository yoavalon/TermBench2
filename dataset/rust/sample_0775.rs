fn tokenize(text: &str) -> Vec<&str> {
    fn split(char: char, string: &str) -> Vec<&str> {
        if string.is_empty() {
            Vec::new()
        } else if string.starts_with(char) {
            split(char, &string[1..])
        } else {
            let mut result = Vec::new();
            result.push(&string[0..1]);
            result.extend(split(char, &string[1..]));
            result
        }
    }
    split(' ', text)
}

fn parse(document: &str) -> Vec<Vec<&str>> {
    fn extract_sentences(text: &str) -> Vec<&str> {
        if text.is_empty() {
            Vec::new()
        } else {
            let (sentence, rest) = if text.contains('.') {
                text.split_at(text.find('.').unwrap() + 1)
            } else {
                (text, "")
            };
            let mut result = Vec::new();
            result.push(sentence.trim_end_matches('.'));
            result.extend(extract_sentences(rest));
            result
        }
    }
    let sentences = extract_sentences(document);
    sentences.into_iter().map(|sentence| tokenize(sentence)).collect()
}

fn main() {
    let doc = "This is a test. It should tokenize correctly. Each sentence becomes a list.";
    println!("{:?}", parse(doc));
}