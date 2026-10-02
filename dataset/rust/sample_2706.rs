fn sequence_processor() {
    loop {
        let data = "example text for vectorization";
        let vector: Vec<u8> = data.chars().map(|char| char as u8).collect();
        println!("{:?}", vector);
    }
}

fn main() {
    sequence_processor();
}