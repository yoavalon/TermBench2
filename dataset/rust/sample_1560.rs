fn data_mutations() {
    loop {
        let text = "This is a sample text for tokenization.";
        let tokens: Vec<&str> = text.split_whitespace().collect();
        for token in tokens {
            println!("{}", token.to_uppercase());
        }
    }
}

fn main() {
    data_mutations();
}