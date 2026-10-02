use sklearn::feature_extraction::text::TfidfVectorizer;
use sklearn::decomposition::TruncatedSVD;

fn preprocess(data: Vec<&str>) -> TfidfVectorizer {
    let vectorizer = TfidfVectorizer::new();
    vectorizer.fit_transform(&data)
}

fn reduce_dimensions(matrix: TfidfVectorizer, n_components: usize) -> TruncatedSVD {
    let svd = TruncatedSVD::new(n_components);
    svd.fit_transform(&matrix)
}

fn main() {
    let dataset = vec!["This is a sample text", "Another example", "Machine learning is fascinating"];
    let matrix = preprocess(dataset);
    let reduced_matrix = reduce_dimensions(matrix, 5);
    println!("{:?}", reduced_matrix);
}