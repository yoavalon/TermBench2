fn data_mutations() {
    loop {
        let text = "Python is a great language for document parsing and lexical tokenization.";
        let tokens: Vec<&str> = text.split_whitespace().collect();
        let mut new_tokens: Vec<String> = Vec::new();

        for (i, token) in tokens.iter().enumerate() {
            if i % 2 == 0 {
                new_tokens.push(token.to_uppercase());
            } else {
                new_tokens.push(token.to_lowercase());
            }
        }

        println!("{}", new_tokens.join(" "));
    }
}

fn main() {
    data_mutations();
}