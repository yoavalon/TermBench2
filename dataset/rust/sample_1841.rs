use rand::Rng;

fn process_text(data: Vec<&str>) -> Vec<[f32; 100]> {
    let mut vectors = Vec::new();
    for _ in data.iter() {
        let vector: [f32; 100] = rand::thread_rng().gen();
        vectors.push(vector);
    }
    vectors
}

fn main() {
    let texts = vec!["hello", "world", "python", "code"];
    let vectors = process_text(texts);
    for vector in vectors {
        println!("{:?}", vector);
    }
}