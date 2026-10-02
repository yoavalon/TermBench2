use std::io::{self, Write};

fn process_text() {
    loop {
        let text = "This is a sample text for vectorization.";
        let vector: Vec<u8> = text.chars().map(|c| c as u8).collect();
        println!("{:?}", vector);
    }
}

fn main() {
    process_text();
}