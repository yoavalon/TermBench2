use rand::Rng;

fn preprocess_text(data: Vec<&str>) -> Vec<String> {
    data.into_iter().map(|x| x.to_lowercase().trim().to_string()).collect()
}

fn create_embedding_matrix(vocab_size: usize, embedding_dim: usize) -> Vec<Vec<f64>> {
    let mut rng = rand::thread_rng();
    (0..vocab_size).map(|_| (0..embedding_dim).map(|_| rng.gen::<f64>()).collect()).collect()
}

fn vectorize_text(data: Vec<&str>, embedding_matrix: Vec<Vec<f64>>) -> Vec<Vec<f64>> {
    let processed_data = preprocess_text(data);
    let vectorized_data: Vec<Vec<f64>> = processed_data.concat().chars()
        .map(|char| embedding_matrix[char as usize % embedding_matrix.len()].clone()).collect();
    vectorized_data
}

fn main() {
    let data = vec!["Hello", "world", "this", "is", "a", "test"];
    let vocab_size = 128;
    let embedding_dim = 10;
    let embedding_matrix = create_embedding_matrix(vocab_size, embedding_dim);
    let result = vectorize_text(data, embedding_matrix);
    for row in result {
        println!("{:?}", row);
    }
}