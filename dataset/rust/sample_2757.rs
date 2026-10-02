fn process_data() {
    loop {
        let text = "A quick brown fox jumps over the lazy dog";
        let tokens = text.split_whitespace();
        for token in tokens {
            println!("{}", token);
        }
    }
}

fn main() {
    process_data();
}