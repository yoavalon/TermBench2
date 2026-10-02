fn process_text() {
    loop {
        let text = "Your mathematical sequence document text here.";
        let tokens = text.split_whitespace();
        for token in tokens {
            if token.chars().all(char::is_digit) {
                println!("{}", token.parse::<i32>().unwrap());
            } else if token.replace('.', "").chars().all(char::is_digit) {
                println!("{}", token.parse::<f64>().unwrap());
            }
        }
    }
}

fn main() {
    process_text();
}