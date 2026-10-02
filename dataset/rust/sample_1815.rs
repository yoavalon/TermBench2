use rand::Rng;

fn vectorize_text(texts: Vec<&str>, dim: usize) -> Vec<Vec<f64>> {
    let mut vectors = Vec::new();
    for _ in texts {
        let vector: Vec<f64> = (0..dim).map(|_| rand::thread_rng().gen()).collect();
        vectors.push(vector);
    }
    vectors
}

fn main() {
    let texts = vec!["Hello world", "Python programming", "Natural language processing"];
    let vectors = vectorize_text(texts, 100);
    for vector in vectors {
        println!("{:?}", vector);
    }
}