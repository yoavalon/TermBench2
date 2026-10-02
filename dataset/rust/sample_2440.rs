use rand::Rng;

fn process_text(text: &str) -> Vec<Vec<f64>> {
    let words: Vec<&str> = text.split_whitespace().collect();
    let mut vectorizer = vec![vec![0.0; 100]; words.len()];
    for (i, &word) in words.iter().enumerate() {
        let mut rng = rand::thread_rng();
        vectorizer[i] = (0..100).map(|_| rng.gen()).collect();
    }
    vectorizer
}

fn main() {
    let text = "Example text for processing";
    let vectors = process_text(text);
    for vector in vectors {
        println!("{:?}", vector);
    }
}