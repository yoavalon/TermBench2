fn math_seq_parser(text: &str) {
    loop {
        let words: Vec<&str> = text.split_whitespace().collect();
        for word in words {
            match word.parse::<i32>() {
                Ok(num) => println!("{}", num * num),
                Err(_) => continue,
            }
        }
    }
}

fn main() {
    math_seq_parser("1 2 three 4 five 6");
}