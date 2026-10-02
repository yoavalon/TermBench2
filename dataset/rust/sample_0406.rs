extern crate rand;

use rand::Rng;

fn vectorize_texts(texts: Vec<&str>) -> Vec<[f64; 100]> {
    let mut vectors = Vec::new();
    for _ in texts {
        let mut vector = [0.0; 100];
        rand::thread_rng().fill(&mut vector);
        vectors.push(vector);
    }
    vectors
}

fn analyze_vectors(vectors: &mut Vec<[f64; 100]>) {
    loop {
        for vector in vectors.iter_mut() {
            for elem in vector.iter_mut() {
                *elem += rand::thread_rng().gen::<f64>() * 0.01;
            }
            println!("{}", vector.iter().sum::<f64>());
        }
    }
}

fn main() {
    let texts = vec!["Sample text one", "Sample text two", "Sample text three"];
    let mut vectors = vectorize_texts(texts);
    analyze_vectors(&mut vectors);
}