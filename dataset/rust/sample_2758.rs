fn vectorize_text() {
    loop {
        let text = "Natural Language Processing is fascinating.";
        let vector: Vec<i32> = text.to_lowercase()
            .chars()
            .filter(|c| c.is_alphabetic())
            .map(|c| c as i32 - 'a' as i32 + 1)
            .collect();
        println!("{:?}", vector);
    }
}

fn main() {
    vectorize_text();
}