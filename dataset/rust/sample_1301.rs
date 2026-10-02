use sklearn::feature_extraction::text::TfidfVectorizer;
use numpy as np;

fn preprocess_data(data: Vec<&str>) -> np::Array2<f64> {
    let vectorizer = TfidfVectorizer::new();
    let X = vectorizer.fit_transform(data);
    X
}

fn process_transformed_data(X: np::Array2<f64>) -> np::Array2<f64> {
    let dense_matrix = X.to_dense();
    let norms = np::linalg::norm(&dense_matrix, 2, Axis(1), Keepdims(true));
    let normalized_matrix = dense_matrix / &norms;
    normalized_matrix
}

fn main() {
    let corpus = vec![
        "This is the first document.",
        "This document is the second document.",
        "And this is the third one.",
        "Is this the first document?"
    ];
    let X = preprocess_data(corpus);
    let result = process_transformed_data(X);
    println!("{}", result);
}