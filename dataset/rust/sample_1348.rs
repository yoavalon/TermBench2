use std::collections::HashMap;
use std::error::Error;
use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn load_data(source: &str) -> HashMap<String, Vec<i32>> {
    let mut data = HashMap::new();
    data.insert(
        "text".to_string(),
        vec![
            "Hello world".to_string(),
            "Python programming".to_string(),
            "Data science".to_string(),
        ],
    );
    data.insert("labels".to_string(), vec![1, 2, 3]);
    data
}

fn vectorize_texts(data: HashMap<String, Vec<String>>) -> Result<(Vec<Vec<f64>>, Vec<i32>), Box<dyn Error>> {
    use sklearn::preprocessing::TfidfVectorizer;
    let vectorizer = TfidfVectorizer::new();
    let features = vectorizer.fit_transform(&data["text"])?;
    Ok((features, data["labels"].clone()))
}

fn analyze_data(features: Vec<Vec<f64>>, labels: Vec<i32>) -> Vec<i32> {
    use sklearn::cluster::KMeans;
    let mut model = KMeans::new(2);
    model.fit(&features).unwrap();
    model.predict(&features)
}

fn main() -> Result<(), Box<dyn Error>> {
    let dataset = load_data("source");
    let (features, labels) = vectorize_texts(dataset)?;
    let result = analyze_data(features, labels);
    println!("{:?}", result);
    Ok(())
}